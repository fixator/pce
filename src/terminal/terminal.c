/*****************************************************************************
 * pce                                                                       *
 *****************************************************************************/

/*****************************************************************************
 * File name:     src/terminal/terminal.c                                    *
 * Created:       2003-04-18 by Hampa Hug <hampa@hampa.ch>                   *
 * Last modified: 2004-05-30 by Hampa Hug <hampa@hampa.ch>                   *
 * Copyright:     (C) 2003-2004 Hampa Hug <hampa@hampa.ch>                   *
 *****************************************************************************/

/*****************************************************************************
 * This program is free software. You can redistribute it and / or modify it *
 * under the terms of the GNU General Public License version 2 as  published *
 * by the Free Software Foundation.                                          *
 *                                                                           *
 * This program is distributed in the hope  that  it  will  be  useful,  but *
 * WITHOUT  ANY   WARRANTY,   without   even   the   implied   warranty   of *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General *
 * Public License for more details.                                          *
 *****************************************************************************/

/* $Id$ */


#include <stdio.h>

#include <terminal/terminal.h>


void trm_init (terminal_t *trm)
{
  trm->ext = NULL;

  trm->key_ext = NULL;
  trm->set_key = NULL;

  trm->mse_ext = NULL;
  trm->set_mse = NULL;

  trm->set_brk = NULL;

  trm->del = NULL;
  trm->set_mode = NULL;
  trm->set_size = NULL;
  trm->set_map = NULL;
  trm->set_col = NULL;
  trm->set_crs = NULL;
  trm->set_pos = NULL;
  trm->set_chr = NULL;
  trm->set_pxl = NULL;
  trm->check = NULL;
}

void trm_free (terminal_t *trm)
{
}

void trm_del (terminal_t *trm)
{
  if (trm->del != NULL) {
    trm->del (trm->ext);
  }
}

void trm_set_mode (terminal_t *trm, unsigned m, unsigned w, unsigned h)
{
  if (trm->set_mode != NULL) {
    trm->set_mode (trm->ext, m, w, h);
  }
}

void trm_set_size (terminal_t *trm, unsigned w, unsigned h)
{
  if (trm->set_size != NULL) {
    trm->set_size (trm->ext, w, h);
  }
}

void trm_set_map (terminal_t *trm, unsigned i, unsigned r, unsigned g, unsigned b)
{
  if (trm->set_map != NULL) {
    trm->set_map (trm->ext, i, r, g, b);
  }
}

void trm_set_col (terminal_t *trm, unsigned fg, unsigned bg)
{
  if (trm->set_col != NULL) {
    trm->set_col (trm->ext, fg, bg);
  }
}

void trm_set_crs (terminal_t *trm, unsigned y1, unsigned y2, int show)
{
  if (trm->set_crs != NULL) {
    trm->set_crs (trm->ext, y1, y2, show);
  }
}

void trm_set_pos (terminal_t *trm, unsigned x, unsigned y)
{
  if (trm->set_pos != NULL) {
    trm->set_pos (trm->ext, x, y);
  }
}

void trm_set_chr (terminal_t *trm, unsigned x, unsigned y, unsigned char c)
{
  if (trm->set_chr != NULL) {
    trm->set_chr (trm->ext, x, y, c);
  }
}

void trm_set_pxl (terminal_t *trm, unsigned x, unsigned y, unsigned w, unsigned h)
{
  if (trm->set_pxl != NULL) {
    trm->set_pxl (trm->ext, x, y, w, h);
  }
}

void trm_check (terminal_t *trm)
{
  if (trm->check != NULL) {
    trm->check (trm->ext);
  }
}
