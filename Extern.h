/**  ***************************************************************  **/
/**  regidx C code - 2016                                             **/
/**                                                                   **/
/**       ** Registry Index for Bilayer Carbon Based Systems **       **/
/**                                                                   **/
/**  Written by Pedro Brandimarte (brandimarte@gmail.com)             **/
/**                                                                   **/
/**  Copyright (c), All Rights Reserved                               **/
/**                                                                   **/
/**  This program is free software. You can redistribute it and/or    **/
/**  modify it under the terms of the GNU General Public License      **/
/**  (version 3 or later) as published by the Free Software           **/
/**  Foundation <http://fsf.org/>.                                    **/
/**                                                                   **/
/**  This program is distributed in the hope that it will be useful,  **/
/**  but WITHOUT ANY WARRANTY, without even the implied warranty of   **/
/**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the     **/
/**  GNU General Public License for more details (file 'LICENSE_GPL'  **/
/**  distributed along with this program or at                        **/
/**  <http://www.gnu.org/licenses/gpl.html>).                         **/
/**  ***************************************************************  **/
/**  File: Extern.h                                                   **/
/**                                                                   **/
/**  Description: Interface for some external functions from LAPACK   **/
/**  and BLAS libraries.                                              **/
/**                                                                   **/
/**  Written by Pedro Brandimarte, Dec 2016.                          **/
/**  Centro de Fisica de Materiales - CFM                             **/
/**  Donostia - San Sebastian, Spain                                  **/
/**  e-mail: brandimarte@gmail.com                                    **/
/**  ***************************** HISTORY *************************  **/
/**  Original version:    January 2016                                **/
/**  ***************************************************************  **/


/* For compiling with old version of Intel MKL. */
#ifdef OLD
#define dsyevd dsyevd_
#define dgetrf dgetrf_
#define dgetri dgetri_
#define dgemm dgemm_
#endif


/* Lapack rotine: computes all eigenvalues and */
/* (optionally) all eigenvectors of a real symmetric */
/* matrix using "divide and conquer" algorithm.      */
void dsyevd (char *jobz, char *uplo, int *n, double *a, int *lda,
	     double *w, double *work, int *lwork, int *iwork,
	     int *liwork, int *info);

/* Lapack rotine: forms a triangular matrix factorization (trf) */
/* from a general matrix (ge) of double precision real (d).     */
void dgetrf (int *m, int *n, double *a, int *lda, int *ipiv, int *info);

/* Lapack rotine: computes the inverse matrix using the factorization */
/* (tri) from a general matrix (ge) of double precision real (d).     */
void dgetri (int *n, double *a, int *lda, int *ipiv,
	    double *work, int *lwork, int *info);

/* Blas rotine: computes a scalar-matrix-matrix product */
/* and adds the result to a scalar-matrix product.      */
void dgemm (char *transa, char *transb, int *m, int *n, int *k,
	    double *alpha, double *a, int *lda, double *b,
	    int *ldb, double *beta, double *c, int *ldc);


/* ***************************** Drafts ****************************** */

