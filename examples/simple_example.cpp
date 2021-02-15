// Copyright (c) 2021 Bartosz Meglicki <meglickib@gmail.com>
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include <iostream>

#include "../footprint_collision_checker.hpp"

class MapMock
{
public:
	bool worldToMap(double wx, double wy, unsigned int &mx, unsigned int &my)
	{
		mx = wx;
		my = wy;
		return true;
	}

	double getCost(int x, int y)
	{
		if(x < 0)
			return 0;

		return 100;
	}

	static constexpr double OCCUPIED = 254;
};

struct PointMock
{
	double x;
	double y;
};

using namespace fcc;
using namespace std;

int main(int argc, char **argv)
{
	MapMock *map = new MapMock();

	FootprintCollisionChecker<MapMock, PointMock> checker(map);

	//initialize some footprint, just a vector<PointMock> here
	FootprintCollisionChecker<MapMock, PointMock>::Footprint footprint;

	footprint.push_back( {-1, -1} );
	footprint.push_back( {1, -1} );
	footprint.push_back( {1, 1});
	footprint.push_back( {-1, 1} );

	cout << "footprint (in the middle) cost " << checker.footprintCost(footprint) << endl;
	cout << "footprint (on the left) cost "   << checker.footprintCostAtPose(-5, 0, 0, footprint) << endl;
	cout << "footprint (on the right) cost "  << checker.footprintCostAtPose(55, 0, 0, footprint) << endl;
	cout << "line (-1,-1) -> (1,1) cost " << checker.lineCost(-1, 1, -1, 1) << endl;

	unsigned int x,y;
	checker.worldToMap(0, 0, x, y);

	//set new map
	checker.setCostmap(map);

	delete map;

	return 0;
}
