/*
 *    sfall
 *    Copyright (C) 2009  Mash (Matt Wells, mashw at bigpond dot net dot au)
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Module.h"

namespace sfall
{

class HeroAppearance : public Module {
public:
	const char* name() { return "HeroAppearance"; }

	void init();

	void exit() override;
};

void _stdcall HeroSelectWindow(int RaceStyleFlag);
void _stdcall SetHeroStyle(int newStyleVal);
void _stdcall SetHeroRace(int newRaceVal);
void _stdcall LoadHeroAppearance(void);
void _stdcall SetNewCharAppearanceGlobals(void);

void _stdcall RefreshPCArt();

}