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

#define MD4M_A  0x67452301
#define MD4M_B  0xefcdab89
#define MD4M_C  0x98badcfe
#define MD4M_D  0x10325476

#define MD4S00  3
#define MD4S01  7
#define MD4S02  11
#define MD4S03  19
#define MD4S10  3
#define MD4S11  5
#define MD4S12  9
#define MD4S13  13
#define MD4S20  3
#define MD4S21  9
#define MD4S22  11
#define MD4S23  15

#define MD4C00  0x00000000
#define MD4C01  0x5a827999
#define MD4C02  0x6ed9eba1

static const uint32_t MD4_MAGIC[4][4] __attribute__ ((aligned (16))) =
{
  { MD4M_A, MD4M_A, MD4M_A, MD4M_A },
  { MD4M_B, MD4M_B, MD4M_B, MD4M_B },
  { MD4M_C, MD4M_C, MD4M_C, MD4M_C },
  { MD4M_D, MD4M_D, MD4M_D, MD4M_D },
};

static const uint32_t MD4_CONST[3][4] __attribute__ ((aligned (16))) =
{
  { MD4C00, MD4C00, MD4C00, MD4C00 },
  { MD4C01, MD4C01, MD4C01, MD4C01 },
  { MD4C02, MD4C02, MD4C02, MD4C02 },
};

#define MD4_F(r,x,y,z)                  \
  _mm_cmov_si128_NN (r, y, z, x);

#define MD4_G(r,x,y,z)                  \
  _mm_xor_si128_NN  (tg, x, y);         \
  _mm_cmov_si128_NN (r, z, x, tg);

#define MD4_H1(r,x,y,z)                 \
  _mm_xor_si128_NN  (th, x, y);         \
  _mm_xor_si128_NN  (r, th, z);

#define MD4_H2(r,x,y,z)                 \
  _mm_xor_si128_NN  (r, x, th);

#define MD4_STEP0(F,a,b,c,d,x,k,s)      \
  _mm_add_epi32_NN  (a, a, x);          \
  F (tf, b, c, d);                      \
  _mm_add_epi32_NN  (a, a, tf);         \
  _mm_roti_epi32_N1 (a, a, s);

#define MD4_STEP12(F,a,b,c,d,x,k,s)     \
  _mm_add_epi32_N1  (a, a, k);          \
  _mm_add_epi32_NN  (a, a, x);          \
  F (tf, b, c, d);                      \
  _mm_add_epi32_NN  (a, a, tf);         \
  _mm_roti_epi32_N1 (a, a, s);

void md4_transform (__m128i dgst[4][INTL], __m128i word[16][INTL])
{
  __m128i *md4_const = (__m128i *) MD4_CONST;

  // temps

  __m128i tf[INTL];
  __m128i tg[INTL];
  __m128i th[INTL];

  __m128i a[INTL];
  __m128i b[INTL];
  __m128i c[INTL];
  __m128i d[INTL];

  // dgst

  _mm_set_epi32_NN (a, dgst[0]);
  _mm_set_epi32_NN (b, dgst[1]);
  _mm_set_epi32_NN (c, dgst[2]);
  _mm_set_epi32_NN (d, dgst[3]);

  // go

  MD4_STEP0  (MD4_F , a, b, c, d, word[ 0], md4_const[0], MD4S00);
  MD4_STEP0  (MD4_F , d, a, b, c, word[ 1], md4_const[0], MD4S01);
  MD4_STEP0  (MD4_F , c, d, a, b, word[ 2], md4_const[0], MD4S02);
  MD4_STEP0  (MD4_F , b, c, d, a, word[ 3], md4_const[0], MD4S03);
  MD4_STEP0  (MD4_F , a, b, c, d, word[ 4], md4_const[0], MD4S00);
  MD4_STEP0  (MD4_F , d, a, b, c, word[ 5], md4_const[0], MD4S01);
  MD4_STEP0  (MD4_F , c, d, a, b, word[ 6], md4_const[0], MD4S02);
  MD4_STEP0  (MD4_F , b, c, d, a, word[ 7], md4_const[0], MD4S03);
  MD4_STEP0  (MD4_F , a, b, c, d, word[ 8], md4_const[0], MD4S00);
  MD4_STEP0  (MD4_F , d, a, b, c, word[ 9], md4_const[0], MD4S01);
  MD4_STEP0  (MD4_F , c, d, a, b, word[10], md4_const[0], MD4S02);
  MD4_STEP0  (MD4_F , b, c, d, a, word[11], md4_const[0], MD4S03);
  MD4_STEP0  (MD4_F , a, b, c, d, word[12], md4_const[0], MD4S00);
  MD4_STEP0  (MD4_F , d, a, b, c, word[13], md4_const[0], MD4S01);
  MD4_STEP0  (MD4_F , c, d, a, b, word[14], md4_const[0], MD4S02);
  MD4_STEP0  (MD4_F , b, c, d, a, word[15], md4_const[0], MD4S03);

  MD4_STEP12 (MD4_G , a, b, c, d, word[ 0], md4_const[1], MD4S10);
  MD4_STEP12 (MD4_G , d, a, b, c, word[ 4], md4_const[1], MD4S11);
  MD4_STEP12 (MD4_G , c, d, a, b, word[ 8], md4_const[1], MD4S12);
  MD4_STEP12 (MD4_G , b, c, d, a, word[12], md4_const[1], MD4S13);
  MD4_STEP12 (MD4_G , a, b, c, d, word[ 1], md4_const[1], MD4S10);
  MD4_STEP12 (MD4_G , d, a, b, c, word[ 5], md4_const[1], MD4S11);
  MD4_STEP12 (MD4_G , c, d, a, b, word[ 9], md4_const[1], MD4S12);
  MD4_STEP12 (MD4_G , b, c, d, a, word[13], md4_const[1], MD4S13);
  MD4_STEP12 (MD4_G , a, b, c, d, word[ 2], md4_const[1], MD4S10);
  MD4_STEP12 (MD4_G , d, a, b, c, word[ 6], md4_const[1], MD4S11);
  MD4_STEP12 (MD4_G , c, d, a, b, word[10], md4_const[1], MD4S12);
  MD4_STEP12 (MD4_G , b, c, d, a, word[14], md4_const[1], MD4S13);
  MD4_STEP12 (MD4_G , a, b, c, d, word[ 3], md4_const[1], MD4S10);
  MD4_STEP12 (MD4_G , d, a, b, c, word[ 7], md4_const[1], MD4S11);
  MD4_STEP12 (MD4_G , c, d, a, b, word[11], md4_const[1], MD4S12);
  MD4_STEP12 (MD4_G , b, c, d, a, word[15], md4_const[1], MD4S13);

  MD4_STEP12 (MD4_H1, a, b, c, d, word[ 0], md4_const[2], MD4S20);
  MD4_STEP12 (MD4_H2, d, a, b, c, word[ 8], md4_const[2], MD4S21);
  MD4_STEP12 (MD4_H1, c, d, a, b, word[ 4], md4_const[2], MD4S22);
  MD4_STEP12 (MD4_H2, b, c, d, a, word[12], md4_const[2], MD4S23);
  MD4_STEP12 (MD4_H1, a, b, c, d, word[ 2], md4_const[2], MD4S20);
  MD4_STEP12 (MD4_H2, d, a, b, c, word[10], md4_const[2], MD4S21);
  MD4_STEP12 (MD4_H1, c, d, a, b, word[ 6], md4_const[2], MD4S22);
  MD4_STEP12 (MD4_H2, b, c, d, a, word[14], md4_const[2], MD4S23);
  MD4_STEP12 (MD4_H1, a, b, c, d, word[ 1], md4_const[2], MD4S20);
  MD4_STEP12 (MD4_H2, d, a, b, c, word[ 9], md4_const[2], MD4S21);
  MD4_STEP12 (MD4_H1, c, d, a, b, word[ 5], md4_const[2], MD4S22);
  MD4_STEP12 (MD4_H2, b, c, d, a, word[13], md4_const[2], MD4S23);
  MD4_STEP12 (MD4_H1, a, b, c, d, word[ 3], md4_const[2], MD4S20);
  MD4_STEP12 (MD4_H2, d, a, b, c, word[11], md4_const[2], MD4S21);
  MD4_STEP12 (MD4_H1, c, d, a, b, word[ 7], md4_const[2], MD4S22);
  MD4_STEP12 (MD4_H2, b, c, d, a, word[15], md4_const[2], MD4S23);

  _mm_add_epi32_NN (dgst[0], dgst[0], a);
  _mm_add_epi32_NN (dgst[1], dgst[1], b);
  _mm_add_epi32_NN (dgst[2], dgst[2], c);
  _mm_add_epi32_NN (dgst[3], dgst[3], d);
}
