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
 */

/*
 * 860ifunc.c 
 *
 * A processing function group peculiar to a model.
 */


/*
 * include necessary headers ...
 */
#include "bscc2sts.h"
#include "commonfunc.h"


/*
 * Ink information is set from warning and an operator call.
 */
int pixus860i_setink(ST_STORESET *p_s, ST_BSCC2STS *p_ct, bscc2sts_tbl *p_tbl, ST_BSCCBUF *p_bsccbuf)
{
  int ret;
  int i=0;
//  int color_num=0;
  char pixus860icolor[]="lLCMY";
//  char *p_tok;

  if( (p_tbl->cartridge[0].type == UNEQUIP)|| (p_tbl->cartridge[0].type == '?')
      || (p_tbl->warning[0]==NOITEM) || (p_tbl->operator_call[0]==NOITEM)
      || (p_bsccbuf+DWS)->p_bsccsts==NULL || (p_bsccbuf+DOC)->p_bsccsts==NULL ){
	return(OK);
  }

  for(i=0; i<MAX860iCOLORNUM; i++){
	p_tbl->ink[i].color=pixus860icolor[i];
	ret=com_warnoperatechk(p_tbl->warning, p_tbl->ink[i].color, sizeof(p_tbl->warning));
	if(ret == OCCUR){
	  strncpy(p_tbl->ink[i].fill, TENPER, sizeof(p_tbl->ink[i].fill));
	  p_tbl->ink[i].alert=INKLOW;
	} else {
	  strncpy(p_tbl->ink[i].fill, FULL, sizeof(p_tbl->ink[i].fill));
	  p_tbl->ink[i].alert=NOALERT;
	}

	p_tbl->ink[i].color=pixus860icolor[i];
	ret=com_warnoperatechk(p_tbl->operator_call, p_tbl->ink[i].color, sizeof(p_tbl->operator_call));
	if(ret == OCCUR){
	  strncpy(p_tbl->ink[i].fill, ZEROPER, sizeof(p_tbl->ink[i].fill));
	  p_tbl->ink[i].alert=INKOUT;
	}
  }
  return(OK);
}

/*
 * CD-R Gude alert convert.
 * .
 */
int pixus860i_setoperate(ST_STORESET *p_s, ST_BSCC2STS *p_ct, bscc2sts_tbl *p_tbl, ST_BSCCBUF *p_bsccbuf)
{
  int ret;
  int i=0;

  if( (p_s->p_bsccsts == NULL) ){
	return(OK);
  }

  ret = com_setoperate( p_s, p_ct, p_tbl);

  for(i=0;i<12;i++){
  	if( p_tbl->warning[i] == 'g' ) break;
  }
  if( i<12 ){
	for(i=0;i<12;i++){
  		if( p_tbl->operator_call[i] == 'O' ){
			p_tbl->operator_call[i] = 'g';
			break;
		}
  	}
  	
  }
  return(OK);
}


