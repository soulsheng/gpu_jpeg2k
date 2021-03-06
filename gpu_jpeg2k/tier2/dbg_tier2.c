/* 
Copyright 2009-2013 Poznan Supercomputing and Networking Center

Authors:
Milosz Ciznicki miloszc@man.poznan.pl

GPU JPEG2K is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

GPU JPEG2K is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with GPU JPEG2K. If not, see <http://www.gnu.org/licenses/>.
*/
/**
 * @file dbg_tier2.c
 *
 * @author Milosz Ciznicki
 */
#include <stdio.h>
#include "tag_tree_encode.h"
#include "dbg_tier2.h"

int values[] = {1, 3, 2, 3, 2, 3, 2, 2, 1, 4, 3, 2, 2, 2, 2, 2, 1, 2};

void dbg_tag_tree()
{
	type_tag_tree *tag_tree;

	tag_tree = create_tag_tree(values, 6, 3);

	int t, i, j;

	for(t = 0; t < tag_tree->tree_lvls; t++)
	{
		printf("%d) w:%d h:%d\n", t, tag_tree->widths[t], tag_tree->heights[t]);
		for(j = 0; j < tag_tree->heights[t]; j++)
		{
			for(i = 0; i < tag_tree->widths[t]; i++)
			{
				printf("%d,", tag_tree->w_vals[t][i + j * tag_tree->widths[t]]);
			}
			printf("\n");
		}
	}
}
