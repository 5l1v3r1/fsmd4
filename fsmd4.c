#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <x86intrin.h>
#include <sys/time.h>

/**
 * Copyright (c) 2013, Jens Steube
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#define LOOPS 10000000
#define INTL  3

#include "interlace.c"
#include "md4.c"

void dump_sse2 (const __m128i v)
{
  uint32_t tmp[4] __attribute__ ((aligned (16)));

  _mm_store_si128 ((__m128i *) tmp, v);

  printf ("%08x %08x %08x %08x\n", tmp[0], tmp[1], tmp[2], tmp[3]);
}

void make_unicode (__m128i in[16][INTL], __m128i out[16][INTL], const int pos)
{
  const int pos2 = pos * 2;

  #ifdef __XOP__

  const __m128i sel_lo = _mm_setr_epi32
  (
    0x80118010,
    0x80158014,
    0x80198018,
    0x801d801c
  );

  const __m128i sel_hi = _mm_setr_epi32
  (
    0x80138012,
    0x80178016,
    0x801b801a,
    0x801f801e
  );

  _mm_perm_epi8_NN1 (out[pos2 + 1], in[pos], in[pos], sel_hi);
  _mm_perm_epi8_NN1 (out[pos2 + 0], in[pos], in[pos], sel_lo);

  #else

  const __m128i zero = _mm_setzero_si128 ();

  __m128i t_lo[INTL];
  __m128i t_hi[INTL];

  _mm_unpacklo_epi8_N1 (t_lo, in[pos], zero);
  _mm_unpackhi_epi8_N1 (t_hi, in[pos], zero);

  _mm_shuffle_epi32_N1 (t_lo, t_lo, _MM_SHUFFLE (2, 0, 3, 1));
  _mm_shuffle_epi32_N1 (t_hi, t_hi, _MM_SHUFFLE (2, 0, 3, 1));

  _mm_unpacklo_epi64_NN (out[pos2 + 1], t_lo, t_hi);
  _mm_unpackhi_epi64_NN (out[pos2 + 0], t_lo, t_hi);

  #endif
}

int main (int argc, char *argv[])
{
  int loops = LOOPS;

  if (argc > 2)
  {
    fprintf (stderr, "usage: %s [loops]", argv[0]);

    return -1;
  }

  if (argc == 2) loops = atoi (argv[1]);

  #ifdef DEBUG
  loops = 1;
  #endif

  int i;
  int j;
  int k;

  __m128i dgst[4][INTL];
  __m128i word[16][INTL];

  for (j = 0; j < 16; j++)
  {
    for (k = 0; k < INTL; k++)
    {
      word[j][k] = _mm_setzero_si128 ();
    }
  }

  word[0][0] = _mm_set1_epi32 (0x80);

  #ifdef DEBUG
  word[ 0][0] = _mm_set1_epi32 (0x61616161);
  word[ 1][0] = _mm_set1_epi32 (0x80);
  word[14][0] = _mm_set1_epi32 (4 * 2 * 8);
  #endif

  struct timeval time_start;

  gettimeofday (&time_start, NULL);

  for (i = 0; i < loops; i++)
  {
    __m128i *md4_magic = (__m128i *) MD4_MAGIC;

    _mm_set_epi32_N1 (dgst[0], md4_magic[0]);
    _mm_set_epi32_N1 (dgst[1], md4_magic[1]);
    _mm_set_epi32_N1 (dgst[2], md4_magic[2]);
    _mm_set_epi32_N1 (dgst[3], md4_magic[3]);

    #ifdef DEBUG
    make_unicode (word, word, 5); // len < 24
    make_unicode (word, word, 4);
    make_unicode (word, word, 3);
    make_unicode (word, word, 2);
    make_unicode (word, word, 1);
    make_unicode (word, word, 0); // len < 4
    #endif

    md4_transform (dgst, word);
  }

  struct timeval time_stop;

  gettimeofday (&time_stop, NULL);

  #ifdef DEBUG
  uint32_t tmp[4] __attribute__ ((aligned (16)));

  _mm_store_si128 ((__m128i *) tmp, dgst[0][0]);

  printf ("MD4(aaaa) = %08x%08x%08x%08x\n",
    (unsigned int) __builtin_bswap32 (tmp[0]),
    (unsigned int) __builtin_bswap32 (tmp[1]),
    (unsigned int) __builtin_bswap32 (tmp[2]),
    (unsigned int) __builtin_bswap32 (tmp[3]));
  #endif

  int us = ((time_stop.tv_sec  - time_start.tv_sec)  * 1000)
         + ((time_stop.tv_usec - time_start.tv_usec) / 1000);

  printf ("%u khash/s\n", (loops * 4 * INTL) / (us + 1));

  return 0;
}
