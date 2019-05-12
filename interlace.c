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

static inline void _mm_set_epi32_N1 (__m128i r[INTL], const __m128i a)
{
  if (INTL >= 1) r[0] = a;
  if (INTL >= 2) r[1] = a;
  if (INTL >= 3) r[2] = a;
  if (INTL >= 4) r[3] = a;
  if (INTL >= 5) r[4] = a;
  if (INTL >= 6) r[5] = a;
  if (INTL >= 7) r[6] = a;
  if (INTL >= 8) r[7] = a;
}

static inline void _mm_set_epi32_NN (__m128i r[INTL], const __m128i a[INTL])
{
  if (INTL >= 1) r[0] = a[0];
  if (INTL >= 2) r[1] = a[1];
  if (INTL >= 3) r[2] = a[2];
  if (INTL >= 4) r[3] = a[3];
  if (INTL >= 5) r[4] = a[4];
  if (INTL >= 6) r[5] = a[5];
  if (INTL >= 7) r[6] = a[6];
  if (INTL >= 8) r[7] = a[7];
}

static inline void _mm_add_epi32_N1 (__m128i r[INTL], const __m128i a[INTL], const __m128i b)
{
  if (INTL >= 1) r[0] = _mm_add_epi32 (a[0], b);
  if (INTL >= 2) r[1] = _mm_add_epi32 (a[1], b);
  if (INTL >= 3) r[2] = _mm_add_epi32 (a[2], b);
  if (INTL >= 4) r[3] = _mm_add_epi32 (a[3], b);
  if (INTL >= 5) r[4] = _mm_add_epi32 (a[4], b);
  if (INTL >= 6) r[5] = _mm_add_epi32 (a[5], b);
  if (INTL >= 7) r[6] = _mm_add_epi32 (a[6], b);
  if (INTL >= 8) r[7] = _mm_add_epi32 (a[7], b);
}

static inline void _mm_add_epi32_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL])
{
  if (INTL >= 1) r[0] = _mm_add_epi32 (a[0], b[0]);
  if (INTL >= 2) r[1] = _mm_add_epi32 (a[1], b[1]);
  if (INTL >= 3) r[2] = _mm_add_epi32 (a[2], b[2]);
  if (INTL >= 4) r[3] = _mm_add_epi32 (a[3], b[3]);
  if (INTL >= 5) r[4] = _mm_add_epi32 (a[4], b[4]);
  if (INTL >= 6) r[5] = _mm_add_epi32 (a[5], b[5]);
  if (INTL >= 7) r[6] = _mm_add_epi32 (a[6], b[6]);
  if (INTL >= 8) r[7] = _mm_add_epi32 (a[7], b[7]);
}

static inline void _mm_xor_si128_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL])
{
  if (INTL >= 1) r[0] = _mm_xor_si128 (a[0], b[0]);
  if (INTL >= 2) r[1] = _mm_xor_si128 (a[1], b[1]);
  if (INTL >= 3) r[2] = _mm_xor_si128 (a[2], b[2]);
  if (INTL >= 4) r[3] = _mm_xor_si128 (a[3], b[3]);
  if (INTL >= 5) r[4] = _mm_xor_si128 (a[4], b[4]);
  if (INTL >= 6) r[5] = _mm_xor_si128 (a[5], b[5]);
  if (INTL >= 7) r[6] = _mm_xor_si128 (a[6], b[6]);
  if (INTL >= 8) r[7] = _mm_xor_si128 (a[7], b[7]);
}

static inline void _mm_and_si128_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL])
{
  if (INTL >= 1) r[0] = _mm_and_si128 (a[0], b[0]);
  if (INTL >= 2) r[1] = _mm_and_si128 (a[1], b[1]);
  if (INTL >= 3) r[2] = _mm_and_si128 (a[2], b[2]);
  if (INTL >= 4) r[3] = _mm_and_si128 (a[3], b[3]);
  if (INTL >= 5) r[4] = _mm_and_si128 (a[4], b[4]);
  if (INTL >= 6) r[5] = _mm_and_si128 (a[5], b[5]);
  if (INTL >= 7) r[6] = _mm_and_si128 (a[6], b[6]);
  if (INTL >= 8) r[7] = _mm_and_si128 (a[7], b[7]);
}

static inline void _mm_and_si128_N1 (__m128i r[INTL], const __m128i a[INTL], const __m128i b)
{
  if (INTL >= 1) r[0] = _mm_and_si128 (a[0], b);
  if (INTL >= 2) r[1] = _mm_and_si128 (a[1], b);
  if (INTL >= 3) r[2] = _mm_and_si128 (a[2], b);
  if (INTL >= 4) r[3] = _mm_and_si128 (a[3], b);
  if (INTL >= 5) r[4] = _mm_and_si128 (a[4], b);
  if (INTL >= 6) r[5] = _mm_and_si128 (a[5], b);
  if (INTL >= 7) r[6] = _mm_and_si128 (a[6], b);
  if (INTL >= 8) r[7] = _mm_and_si128 (a[7], b);
}

static inline void _mm_or_si128_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL])
{
  if (INTL >= 1) r[0] = _mm_or_si128 (a[0], b[0]);
  if (INTL >= 2) r[1] = _mm_or_si128 (a[1], b[1]);
  if (INTL >= 3) r[2] = _mm_or_si128 (a[2], b[2]);
  if (INTL >= 4) r[3] = _mm_or_si128 (a[3], b[3]);
  if (INTL >= 5) r[4] = _mm_or_si128 (a[4], b[4]);
  if (INTL >= 6) r[5] = _mm_or_si128 (a[5], b[5]);
  if (INTL >= 7) r[6] = _mm_or_si128 (a[6], b[6]);
  if (INTL >= 8) r[7] = _mm_or_si128 (a[7], b[7]);
}

static inline void _mm_move_epi64_NN (__m128i r[INTL], const __m128i a[INTL])
{
  if (INTL >= 1) r[0] = _mm_move_epi64 (a[0]);
  if (INTL >= 2) r[1] = _mm_move_epi64 (a[1]);
  if (INTL >= 3) r[2] = _mm_move_epi64 (a[2]);
  if (INTL >= 4) r[3] = _mm_move_epi64 (a[3]);
  if (INTL >= 5) r[4] = _mm_move_epi64 (a[4]);
  if (INTL >= 6) r[5] = _mm_move_epi64 (a[5]);
  if (INTL >= 7) r[6] = _mm_move_epi64 (a[6]);
  if (INTL >= 8) r[7] = _mm_move_epi64 (a[7]);
}

static inline void _mm_slli_epi32_N1 (__m128i r[INTL], const __m128i a[INTL], const int b)
{
  if (INTL >= 1) r[0] = _mm_slli_epi32 (a[0], b);
  if (INTL >= 2) r[1] = _mm_slli_epi32 (a[1], b);
  if (INTL >= 3) r[2] = _mm_slli_epi32 (a[2], b);
  if (INTL >= 4) r[3] = _mm_slli_epi32 (a[3], b);
  if (INTL >= 5) r[4] = _mm_slli_epi32 (a[4], b);
  if (INTL >= 6) r[5] = _mm_slli_epi32 (a[5], b);
  if (INTL >= 7) r[6] = _mm_slli_epi32 (a[6], b);
  if (INTL >= 8) r[7] = _mm_slli_epi32 (a[7], b);
}

static inline void _mm_srli_epi32_N1 (__m128i r[INTL], const __m128i a[INTL], const int b)
{
  if (INTL >= 1) r[0] = _mm_srli_epi32 (a[0], b);
  if (INTL >= 2) r[1] = _mm_srli_epi32 (a[1], b);
  if (INTL >= 3) r[2] = _mm_srli_epi32 (a[2], b);
  if (INTL >= 4) r[3] = _mm_srli_epi32 (a[3], b);
  if (INTL >= 5) r[4] = _mm_srli_epi32 (a[4], b);
  if (INTL >= 6) r[5] = _mm_srli_epi32 (a[5], b);
  if (INTL >= 7) r[6] = _mm_srli_epi32 (a[6], b);
  if (INTL >= 8) r[7] = _mm_srli_epi32 (a[7], b);
}

static inline void _mm_unpacklo_epi64_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL])
{
  if (INTL >= 1) r[0] = _mm_unpacklo_epi64 (a[0], b[0]);
  if (INTL >= 2) r[1] = _mm_unpacklo_epi64 (a[1], b[1]);
  if (INTL >= 3) r[2] = _mm_unpacklo_epi64 (a[2], b[2]);
  if (INTL >= 4) r[3] = _mm_unpacklo_epi64 (a[3], b[3]);
  if (INTL >= 5) r[4] = _mm_unpacklo_epi64 (a[4], b[4]);
  if (INTL >= 6) r[5] = _mm_unpacklo_epi64 (a[5], b[5]);
  if (INTL >= 7) r[6] = _mm_unpacklo_epi64 (a[6], b[6]);
  if (INTL >= 8) r[7] = _mm_unpacklo_epi64 (a[7], b[7]);
}

static inline void _mm_unpackhi_epi64_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL])
{
  if (INTL >= 1) r[0] = _mm_unpackhi_epi64 (a[0], b[0]);
  if (INTL >= 2) r[1] = _mm_unpackhi_epi64 (a[1], b[1]);
  if (INTL >= 3) r[2] = _mm_unpackhi_epi64 (a[2], b[2]);
  if (INTL >= 4) r[3] = _mm_unpackhi_epi64 (a[3], b[3]);
  if (INTL >= 5) r[4] = _mm_unpackhi_epi64 (a[4], b[4]);
  if (INTL >= 6) r[5] = _mm_unpackhi_epi64 (a[5], b[5]);
  if (INTL >= 7) r[6] = _mm_unpackhi_epi64 (a[6], b[6]);
  if (INTL >= 8) r[7] = _mm_unpackhi_epi64 (a[7], b[7]);
}

static inline void _mm_unpacklo_epi8_N1 (__m128i r[INTL], const __m128i a[INTL], const __m128i b)
{
  if (INTL >= 1) r[0] = _mm_unpacklo_epi8 (a[0], b);
  if (INTL >= 2) r[1] = _mm_unpacklo_epi8 (a[1], b);
  if (INTL >= 3) r[2] = _mm_unpacklo_epi8 (a[2], b);
  if (INTL >= 4) r[3] = _mm_unpacklo_epi8 (a[3], b);
  if (INTL >= 5) r[4] = _mm_unpacklo_epi8 (a[4], b);
  if (INTL >= 6) r[5] = _mm_unpacklo_epi8 (a[5], b);
  if (INTL >= 7) r[6] = _mm_unpacklo_epi8 (a[6], b);
  if (INTL >= 8) r[7] = _mm_unpacklo_epi8 (a[7], b);
}

static inline void _mm_unpackhi_epi8_N1 (__m128i r[INTL], const __m128i a[INTL], const __m128i b)
{
  if (INTL >= 1) r[0] = _mm_unpackhi_epi8 (a[0], b);
  if (INTL >= 2) r[1] = _mm_unpackhi_epi8 (a[1], b);
  if (INTL >= 3) r[2] = _mm_unpackhi_epi8 (a[2], b);
  if (INTL >= 4) r[3] = _mm_unpackhi_epi8 (a[3], b);
  if (INTL >= 5) r[4] = _mm_unpackhi_epi8 (a[4], b);
  if (INTL >= 6) r[5] = _mm_unpackhi_epi8 (a[5], b);
  if (INTL >= 7) r[6] = _mm_unpackhi_epi8 (a[6], b);
  if (INTL >= 8) r[7] = _mm_unpackhi_epi8 (a[7], b);
}

static inline void _mm_shuffle_epi32_N1 (__m128i r[INTL], const __m128i a[INTL], const int b)
{
  if (INTL >= 1) r[0] = _mm_shuffle_epi32 (a[0], b);
  if (INTL >= 2) r[1] = _mm_shuffle_epi32 (a[1], b);
  if (INTL >= 3) r[2] = _mm_shuffle_epi32 (a[2], b);
  if (INTL >= 4) r[3] = _mm_shuffle_epi32 (a[3], b);
  if (INTL >= 5) r[4] = _mm_shuffle_epi32 (a[4], b);
  if (INTL >= 6) r[5] = _mm_shuffle_epi32 (a[5], b);
  if (INTL >= 7) r[6] = _mm_shuffle_epi32 (a[6], b);
  if (INTL >= 8) r[7] = _mm_shuffle_epi32 (a[7], b);
}

#ifdef __XOP__

static inline void _mm_perm_epi8_NN1 (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL], const __m128i c)
{
  if (INTL >= 1) r[0] = _mm_perm_epi8 (a[0], b[0], c);
  if (INTL >= 2) r[1] = _mm_perm_epi8 (a[1], b[1], c);
  if (INTL >= 3) r[2] = _mm_perm_epi8 (a[2], b[2], c);
  if (INTL >= 4) r[3] = _mm_perm_epi8 (a[3], b[3], c);
  if (INTL >= 5) r[4] = _mm_perm_epi8 (a[4], b[4], c);
  if (INTL >= 6) r[5] = _mm_perm_epi8 (a[5], b[5], c);
  if (INTL >= 7) r[6] = _mm_perm_epi8 (a[6], b[6], c);
  if (INTL >= 8) r[7] = _mm_perm_epi8 (a[7], b[7], c);
}

static inline void _mm_perm_epi8_1N1 (__m128i r[INTL], const __m128i a, const __m128i b[INTL], const __m128i c)
{
  if (INTL >= 1) r[0] = _mm_perm_epi8 (a, b[0], c);
  if (INTL >= 2) r[1] = _mm_perm_epi8 (a, b[1], c);
  if (INTL >= 3) r[2] = _mm_perm_epi8 (a, b[2], c);
  if (INTL >= 4) r[3] = _mm_perm_epi8 (a, b[3], c);
  if (INTL >= 5) r[4] = _mm_perm_epi8 (a, b[4], c);
  if (INTL >= 6) r[5] = _mm_perm_epi8 (a, b[5], c);
  if (INTL >= 7) r[6] = _mm_perm_epi8 (a, b[6], c);
  if (INTL >= 8) r[7] = _mm_perm_epi8 (a, b[7], c);
}

static inline void _mm_cmov_si128_NN (__m128i r[INTL], const __m128i a[INTL], const __m128i b[INTL], const __m128i c[INTL])
{
  if (INTL >= 1) r[0] = _mm_cmov_si128 (a[0], b[0], c[0]);
  if (INTL >= 2) r[1] = _mm_cmov_si128 (a[1], b[1], c[1]);
  if (INTL >= 3) r[2] = _mm_cmov_si128 (a[2], b[2], c[2]);
  if (INTL >= 4) r[3] = _mm_cmov_si128 (a[3], b[3], c[3]);
  if (INTL >= 5) r[4] = _mm_cmov_si128 (a[4], b[4], c[4]);
  if (INTL >= 6) r[5] = _mm_cmov_si128 (a[5], b[5], c[5]);
  if (INTL >= 7) r[6] = _mm_cmov_si128 (a[6], b[6], c[6]);
  if (INTL >= 8) r[7] = _mm_cmov_si128 (a[7], b[7], c[7]);
}

static inline void _mm_roti_epi32_N1 (__m128i r[INTL], const __m128i a[INTL], const int b)
{
  if (INTL >= 1) r[0] = _mm_roti_epi32 (a[0], b);
  if (INTL >= 2) r[1] = _mm_roti_epi32 (a[1], b);
  if (INTL >= 3) r[2] = _mm_roti_epi32 (a[2], b);
  if (INTL >= 4) r[3] = _mm_roti_epi32 (a[3], b);
  if (INTL >= 5) r[4] = _mm_roti_epi32 (a[4], b);
  if (INTL >= 6) r[5] = _mm_roti_epi32 (a[5], b);
  if (INTL >= 7) r[6] = _mm_roti_epi32 (a[6], b);
  if (INTL >= 8) r[7] = _mm_roti_epi32 (a[7], b);
}

#else

static inline void _mm_cmov_si128_NN (__m128i r[INTL], const __m128i x[INTL], const __m128i y[INTL], const __m128i z[INTL])
{
  __m128i tc[INTL];

  _mm_xor_si128_NN  (tc, x, y);
  _mm_and_si128_NN  (tc, z, tc);
  _mm_xor_si128_NN  (r,  y, tc);
}

static inline void _mm_roti_epi32_N1 (__m128i r[INTL], const __m128i a[INTL], const int s)
{
  __m128i tl[INTL];
  __m128i tr[INTL];

  _mm_slli_epi32_N1 (tl, a, s);
  _mm_srli_epi32_N1 (tr, a, (32 - s));
  _mm_or_si128_NN   (r, tl, tr);
}

#endif
