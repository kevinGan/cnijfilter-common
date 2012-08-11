/*  Canon Bubble Jet Print Filter.
 *  Copyright CANON INC. 2001-2004
 *  All Rights Reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * NOTE:
 *  - As a special exception, this program is permissible to link with the
 *    libraries released as the binary modules.
 *  - If you write modifications of your own for these programs, it is your
 *    choice whether to permit this exception to apply to your modifications.
 *    If you do not wish that, delete this exception.
*/

#define		FIT_OFF		0
#define		FIT_SHORT	1
#define		FIT_LONG	2
#define		LOCATION_UPPERLEFT	0
#define		LOCATION_CENTER		1

#define		REVPRINT_OFF	0
#define		REVPRINT_ON		1

#define		COLLATE_OFF		0
#define		COLLATE_ON		1

typedef struct BJFLT_UISETUP	/* other UI setup */
{
	short	bjflt_fit;			/* fit for printarea */
	short	bjflt_percent;		/* percent (%) */
	short	bjflt_extension;	/* amount of extention for borderless printing */	
	short	bjflt_location;		/* location */	
	short	bjflt_copies;		/* copies */
	short	bjflt_revprint;		/* reverse print */
	short	bjflt_collate;		/* collate */
	short	reserve[9];
} BJFLT_UISETUP, *LPBJFLT_UISETUP;


typedef union {
	struct {
		short				scaling;
		short				position;
		BJFLTDEVICE			bjfltdev;
		CNCLPAPERSIZE		papersize;
		BJFLTCOLORSYSTEM	bjfltcolor;
		BJFLT_UISETUP		bjflt_uisetup;
	} parm;

	struct {
		long				cmdslen;
		char				cmds[512];
	} cmds;
} IPCU, *LPIPCU;

#define	RET_PRINT	0
#define	RET_ERROR	1
#define	RET_CANCEL	10
#define	RET_PDATA	20
#define RET_EXECLM	30

#define	IPCCMDLEN	128
