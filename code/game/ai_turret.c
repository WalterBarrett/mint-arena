/*
===========================================================================
Copyright (C) 1999-2010 id Software LLC, a ZeniMax Media company.

This file is part of Spearmint Source Code.

Spearmint Source Code is free software; you can redistribute it
and/or modify it under the terms of the GNU General Public License as
published by the Free Software Foundation; either version 3 of the License,
or (at your option) any later version.

Spearmint Source Code is distributed in the hope that it will be
useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Spearmint Source Code.  If not, see <http://www.gnu.org/licenses/>.

In addition, Spearmint Source Code is also subject to certain additional terms.
You should have received a copy of these additional terms immediately following
the terms and conditions of the GNU General Public License.  If not, please
request a copy in writing from id Software at the address below.

If you have questions concerning this license or the applicable additional
terms, you may contact in writing id Software LLC, c/o ZeniMax Media Inc.,
Suite 120, Rockville, Maryland 20850 USA.
===========================================================================
*/
//
// ai_turret.c -- turret AI-related functions

#include "g_local.h"
#include "../botlib/botlib.h"
#include "../botlib/be_aas.h"
#include "ai_goal.h"
#include "ai_move.h"
#include "ai_main.h"
#include "ai_dmq3.h"
#include "ai_turret.h"


/*
====================
TurretVisibleEnemies
====================
*/
gentity_t *TurretFindVisibleEnemy(int turretentnum, vec3_t eye, vec3_t viewangles) {
	float vis;
	int i;
	aas_entityinfo_t entinfo;

	for (i = 0; i < MAX_CLIENTS; i++) {
		BotEntityInfo(i, &entinfo);
		if (!entinfo.valid) {
			continue;
		}

		//if the enemy isn't dead, is invisible, or isn't an enemy
		if (EntityIsDead(&entinfo) || EntityIsInvisible(&entinfo) || OnSameTeam(&g_entities[turretentnum], &g_entities[i])) {
			continue;
		}

		//check if the enemy is visible
		vis = BotEntityVisible(turretentnum, eye, viewangles, 360, i);
		if (vis > 0) return &g_entities[i];
	}

	return NULL;
}
