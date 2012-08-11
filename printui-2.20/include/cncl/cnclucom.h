/*
 *  Canon Bubble Jet Print Filter for Linux
 *  Copyright CANON INC. 2001-2004 
 *  All Right Reserved.
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

#ifndef _CNCLUCOM_H_
#define	_CNCLUCOM_H_

typedef struct{
	char	OrgDataBaseName[16];		/* Data Base File Name */
	long	reserve[20];
} CNCLNAMEINFO, *LPCNCLNAMEINFO;

typedef struct{
	short	nObjectID;					/* Object ID */
	short	nValue;						/* set value */
	short	defset;						/* default flag */
	short	curset;						/* current flag */
	short	tmpset;						/* tmp flag */
	short	disable;					/* disable flag */
} CNCLDB, *LPCNCLDB;

typedef struct BJFLTDEVICE{
	short	bjfltModelID ;
	short	bjfltInkType ;
	short	bjfltMediaType ;
	short	bjfltPaperSize ;
	short	bjfltMediaSupply ;
	short	bjfltBinMethod ;
	short	bjfltGrayScale ;
	short	bjfltPrintQuality ;
	short	bjfltBanner ;
	long	bjfltPaperWidth ;
	long	bjfltPaperHeight ;
	short	bjfltMarginType ;
	short	bjfltPaperGap;
	short	reserve[8];
} BJFLTDEVICE, *LPBJFLTDEVICE;

typedef struct {
	short	bjfltIntent;
	short	bjfltGamma;
	short	bjfltBalanceC;
	short	bjfltBalanceM;
	short	bjfltBalanceY;
	short	bjfltBalanceK;
	short	bjfltDensity;
	short	reserv[10];
} BJFLTCOLORSYSTEM, *LPBJFLTCOLORSYSTEM;


typedef struct {
	long	nMinCustomWidth;	/* user defined min papersize horizontal  */
	long	nMaxCustomWidth;	/* user defined max papersize horizontal */
	long	nMinCustomLength;	/* user defined min papersize vertical */
	long	nMaxCustomLength;	/* user defined max papersize vertical */
	long	nSelPaperWidth;		/* selected paper width */
	long	nSelPaperLength;	/* selected paper length */
	long	nTopMargin;			/* top margin */
	long	nLeftMargin;		/* left margin */
	long	nWidthPrintArea;		/* width can print */
	long	nLengthPrintArea;	/* length can print */
} CNCLPAPERSIZE, *LPCNCLPAPERSIZE;

typedef struct {
	short	bjfltInkCartridge;		/*CNCL InkType ID.(!= bjfltInkType) */
	short	bjfltInputHResolution;	/*driver horizontal resolution */
	short	bjfltInputVResolution;	/*driver vertical resolution */
	short	reserv[16];
} BJFLTCOMSYSTEM, *LPBJFLTCOMSYSTEM;

/*-------------------------------------------------------------------
			FUNCTION PROTOTYPES
-------------------------------------------------------------------*/
extern short CNCL_GetDBName( LPCNCLNAMEINFO , void *, short  );
extern short CNCL_GetDBSize( LPCNCLNAMEINFO , void * );
extern short CNCL_GetEntries( LPCNCLNAMEINFO , void *, LPCNCLDB  );
extern short CNCL_GetDefaults( LPCNCLNAMEINFO , void *, LPCNCLDB , short  );
extern short CNCL_InitMenulink( LPCNCLNAMEINFO , void *, LPCNCLDB , short  );
extern short CNCL_GetMenulink( LPCNCLNAMEINFO , void *, LPCNCLDB, short  );
extern short CNCL_GetMargin( LPCNCLNAMEINFO, void *, LPCNCLDB, LPCNCLPAPERSIZE, short );
extern short CNCL_GetComSystem( LPCNCLNAMEINFO, void *, LPBJFLTDEVICE, LPBJFLTCOMSYSTEM );
#endif

