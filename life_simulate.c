#pragma warning(push, 0)
#include <stdint.h>

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#include <windows.h>
#pragma(pop)

#pragma warning(disable :5045)

typedef struct
{
	uint32_t x;
	uint32_t y;
} start_coord_t;

// else
// {
// 	OutputDebugStringA("Oh no\n");
// }

uint8_t *simulate_life(uint32_t grid_dim, start_coord_t *initial_points, uint32_t initial_point_count)
{
	// uint8_t *return_grid = (uint8_t*)calloc((grid_dim * grid_dim));
	int i = 0;
	int index = 0;
	static uint8_t *return_grid = NULL;
	static int important;
	if (return_grid == NULL)
	{
		return_grid = VirtualAlloc(0, grid_dim*grid_dim*2, MEM_RESERVE|MEM_COMMIT, PAGE_READWRITE);
		while(i < initial_point_count)
		{
			index = (initial_points[i].y * grid_dim) + initial_points[i].x;
			return_grid[index] = 1;
			i++;
		}
		return (return_grid);
	}
	int gridsize = grid_dim*grid_dim;
	if (grid_dim != 2048)
	{
	i = 0;
	int alive = 0;
	int tump = 0;
	for (;return_grid[tump] == 0;tump++)
		;
	tump -= grid_dim;
	if (tump < 0)
		tump = 0;
	i = tump;
	int tomp = gridsize;
	for(;return_grid[tomp] == 0 && tomp > 0; tomp--)
		;
	tomp += grid_dim;
	if (tomp > gridsize)
		tomp -= gridsize;
	if (grid_dim == 16)
	{
		i = 0;
		tomp = gridsize;
	}
	while(i < tomp)
	{
		int row = i / grid_dim;
		int col = i % grid_dim;
		int alive = 0;

	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (dr == 0 && dc == 0) continue;
			int r = (row + dr + grid_dim) % grid_dim;
			int c = (col + dc + grid_dim) % grid_dim;

		int neighbor_index = r * grid_dim + c;
		if (return_grid[neighbor_index] == 1) alive++;
		}
	}
	if (return_grid[i] == 1) 
	{
		if (alive == 2 || alive == 3)
			return_grid[i + gridsize] = 1;
		else
			return_grid[i + gridsize] = 0;
	}
	else
	{
		if (alive == 3)
			return_grid[i + gridsize] = 1;
		else
			return_grid[i + gridsize] = 0;
	}
		alive = 0;
		i++;
	}
	}
	else
	{
		int tump = 0;
	for (;return_grid[tump] == 0;tump++)
		;
	tump -= grid_dim;
	if (tump < 0)
		tump = 0;
	i = tump;
	int tomp = gridsize / 4;
	for(;return_grid[tomp] == 0 && tomp > 0; tomp--)
		;
	tomp += grid_dim;
	if (tomp > gridsize)
		tomp -= gridsize;
	while(i < tomp)
	{
		int row = i / grid_dim;
		int col = i % grid_dim;
		int alive = 0;

	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (dr == 0 && dc == 0) continue;
			int r = (row + dr + grid_dim) % grid_dim;
			int c = (col + dc + grid_dim) % grid_dim;

		int neighbor_index = r * grid_dim + c;
		if (return_grid[neighbor_index] == 1) alive++;
		}
	}
	if (return_grid[i] == 1) 
	{
		if (alive == 2 || alive == 3)
			return_grid[i + gridsize] = 1;
		else
			return_grid[i + gridsize] = 0;
	}
	else
	{
		if (alive == 3)
			return_grid[i + gridsize] = 1;
		else
			return_grid[i + gridsize] = 0;
	}
		alive = 0;
		i++;
	}
	//owo
	for (;return_grid[tump] == gridsize / 2;tump++)
		;
	tump -= grid_dim;
	if (tump < 0)
		tump = 0;
	i = tump;
	tomp = gridsize;
	for(;return_grid[tomp] == 0 && tomp > 0; tomp--)
		;
	tomp += grid_dim;
	if (tomp > gridsize)
		tomp -= gridsize;
		//owo
	while(i < tomp)
	{
		int row = i / grid_dim;
		int col = i % grid_dim;
		int alive = 0;

	for (int dr = -1; dr <= 1; dr++)
	{
		for (int dc = -1; dc <= 1; dc++)
		{
			if (dr == 0 && dc == 0) continue;
			int r = (row + dr + grid_dim) % grid_dim;
			int c = (col + dc + grid_dim) % grid_dim;

		int neighbor_index = r * grid_dim + c;
		if (return_grid[neighbor_index] == 1) alive++;
		}
	}
	if (return_grid[i] == 1) 
	{
		if (alive == 2 || alive == 3)
			return_grid[i + gridsize] = 1;
		else
			return_grid[i + gridsize] = 0;
	}
	else
	{
		if (alive == 3)
			return_grid[i + gridsize] = 1;
		else
			return_grid[i + gridsize] = 0;
	}
		alive = 0;
		i++;
	}
	}
	for (i = 0; i<gridsize;i++)
	{
		return_grid[i] = return_grid[i + gridsize];
	}

	return return_grid;
}