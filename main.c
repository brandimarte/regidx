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
/**  File: main.c                                                     **/
/**                                                                   **/
/**  Description: This is a (client) program that receives 2 'xyz'    **/
/**  files, containing the x, y and z coordinates from the carbon     **/
/**  atoms from the bottom and top structures, and compute the        **/
/**  registry index defined as:                                       **/
/**                                                                   **/
/**    RI = (S_{cc} - S^{AB}_{cc}) / (S^{AA}_{cc} - S^{AB}_{cc}),     **/
/**                                                                   **/
/**  where 'S_{cc}' is the projected overlap between circles          **/
/**  assigned to each carbon atomic center from different layers.     **/
/**  The RI is normalized considering the case with biggest           **/
/**  interlayer overlapping (worst case) which happens to be the AA   **/
/**  stacking, and the case with lowest overlapping (optimal case)    **/
/**  which happens to be the AB stacking.                             **/
/**                                                                   **/
/**  Usage: ./regidx bottom.xyz top.xyz                               **/
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
#include <time.h>
#include "Utils.h"
/* #include "Phonon.h" */

/* Prints the header on the screen. */
static void header ();

/* Prints the "how to run" on the screen. */
static void howto ();

int main (int nargs, char *arg[])
{
   /* int nDynTot, nDynOrb, spinPol, calcType; */
   /* double *EigVec, *EigVal, *Meph; */
   double time;
   clock_t inicial, final;

   /* Writes the header on the screen. */
   header ();

   /* Checks if the input were typed correctly. */
   if (nargs < 2 || nargs > 3) {
      fprintf (stderr, "\n Wrong number of arguments!\n");
      howto ();
      exit (EXIT_FAILURE);
   }

   /* Time is running. */
   inicial = clock();

   /* Reads info from FC fdf input file. */
   /* PHONreadFCfdf (arg[0], arg[1], arg[2], calcType, arg[4], */
   /* 		  &nDynTot, &nDynOrb, &spinPol); */

   /* Computes phonon frequencies. */
   /* EigVec = UTILdoubleVector (nDynTot * nDynTot); */
   /* EigVal = UTILdoubleVector (nDynTot); */
   /* PHONfreq (EigVec, EigVal); */

   /* Writes a 'xyz' file for each computed phonon mode. */
   /* PHONjmolVib (EigVec); */

   /* Frees memory. */
   /* free (EigVec); */
   /* free (EigVal); */
   /* free (Meph); */

   /* Calculates the execution time. */
   final = clock();
   time = (double)(final - inicial) / CLOCKS_PER_SEC;
   printf ("\n This calculation took %.2f seconds.\n\n", time);

   return 0;
   
} /* main */


/* ******************************************************************* */
/* Prints the header on 'stdout'.                                      */
static void header ()
{
   printf("\n");
   printf("**  *******************************************************\t"
	  "********  **\n");
   printf("**              ** WELCOME TO REGIDX C CODE v2016.01 **    \t"
	  "          **\n\n");
   printf("**        * Registry Index for Bilayer Carbon Based Systems\t"
	  " *        **\n\n");
   printf("**  Written by Pedro Brandimarte (brandimarte@gmail.com)   \t"
	  "          **\n\n");
   printf("**  Copyright (c), All Rights Reserved                     \t"
	  "          **\n\n");
   printf("**  This program is free software. You can redistribute it \t"
	  "and/or    **\n");
   printf("**  modify it under the terms of the GNU General Public \t"
	  "License      **\n");
   printf("**  (version 3 or later) as published by the Free Software \t"
	  "          **\n");
   printf("**  Foundation <http://fsf.org/>. See the GNU General \t"
	  "Public         **\n");
   printf("**  License for more details.                              \t"
	  "          **\n");
   printf("**  *******************************************************\t"
	  "********  **\n");
   setvbuf (stdout, NULL, _IONBF, 0); /* print now! */

} /* header */


/* ******************************************************************* */
/* Prints the "how to run" on 'stdout'.                                */
static void howto ()
{

   fprintf (stderr, "\n Usage: regidx"); /* arg[0] */
   fprintf (stderr, " [bottom xyz coordinate file]"); /* arg[1] */
   fprintf (stderr, " [top xyz coordinate file]\n\n"); /* arg[2] */
   fprintf (stderr, " Example : regidx bottom.xyz top.xyz\n\n");

} /* howto */
