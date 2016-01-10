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
/**  File: Utils.c                                                    **/
/**                                                                   **/
/**  Description: Implementation of matrix (vector) algebra           **/
/**  utilities.                                                       **/
/**                                                                   **/
/**  Written by Pedro Brandimarte, Dec 2016.                          **/
/**  Centro de Fisica de Materiales - CFM                             **/
/**  Donostia - San Sebastian, Spain                                  **/
/**  e-mail: brandimarte@gmail.com                                    **/
/**  ***************************** HISTORY *************************  **/
/**  Original version:    January 2016                                **/
/**  ***************************************************************  **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Check.h"
#include "Utils.h"


/**  **************** Matrix and Vectors Utilities *****************  **/

/* ******************************************************************* */
/* Allocates and initialize a vector 'V[n]' of integers.               */
void *UTILintVector (int n)
{
   register int i;
   int *V;

   V = CHECKmalloc (n * sizeof (int));

   for (i = 0; i < n; i++)
      V[i] = 0;

   return V;

} /* UTILintVector */


/* ******************************************************************* */
/* Allocates and initializes a vector 'V[n]' of doubles.               */
void *UTILdoubleVector (int n)
{
   register int i;
   double *V;

   V = CHECKmalloc (n * sizeof (double));

   for (i = 0; i < n; i++)
      V[i] = 0.0;

   return V;

} /* UTILdoubleVector */


/* ******************************************************************* */
/* Resets a vector 'V[n]' of doubles with 0.0's.                       */
void UTILresetDoubleVector (int n, double *V)
{
   register int i;

   for (i = 0; i < n; i++)
      V[i] = 0.0;

} /* UTILresetDoubleVector */


/* ******************************************************************* */
/* Copies the elements form a vector 'Orig[n]' to another vector       */
/* 'Dest[n]'.                                                          */
void UTILcopyVector (double *Dest, double *Orig, int n)
{
   register int i;

   for (i = 0; i < n; i++)
      Dest[i] = Orig[i];

} /* UTILcopyVector */

/* ******************************************************************* */
/* Checks if the matrix 'M[n][n]' is symetric.                         */
void UTILcheckSym (char *name, double *M, int n, double lim)
{
   register int i, j;

   for (j = 0; j < n - 1; j++)
      for (i = j + 1; i < n; i++)
	 if (fabs(M[idx(i,j,n)] - M[idx(j,i,n)]) > lim) {
	    printf ("\n The matrix %s is not symmetric!\n", name);
	    return ;
	 }

} /* UTILcheckSym */


/* ******************************************************************* */
/* Computes the Euclidean norm of a double precision vector 'V[n]'.    */
double UTILnorm (int n, double *V)
{
   register int i;
   double x = 0.0;

   for (i = 0; i < n; i++)
      x = x + V[i] * V[i];

   return (sqrt(x));

} /* UTILnorm */


/* ***************************** Drafts ****************************** */


