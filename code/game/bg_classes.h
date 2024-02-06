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
// bg_classes.h -- class-related definitions shared by both the server game and client game modules

typedef enum teamClass_s {
	CLASS_CIVILIAN,

	CLASS_SCOUT,
	CLASS_GUARD,
	CLASS_DOUBLER,
	CLASS_AMMOREGEN,

	NUM_CLASSES,

	CLASS_RANDOM,

	FIRST_STANDARD_CLASS = CLASS_SCOUT,
	LAST_STANDARD_CLASS = CLASS_AMMOREGEN,
	NUM_STANDARD_CLASSES = LAST_STANDARD_CLASS - FIRST_STANDARD_CLASS + 1,
} teamClass_t;

struct classInfo_s {
	const char * unalignedModel;
	const char * redModel;
	const char * blueModel;
	powerup_t powerup;
};

typedef struct classInfo_s classInfo_t;

extern classInfo_t playerClasses[NUM_CLASSES];
