#include "Pathfind.h"



string Pathfind::pathFindCooP(const float & xStart, const float & yStart, const float & xFinish, const float & yFinish)
{
	
		static priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
		static int pqi; // pq index
		static Node* n0;
		static Node* m0;
		int i;
		int j;
		int px;
		int py;
		int xdx;
		int ydy;
		int time = 0;

		static char c;
		pqi = 0;
		int level;


		// reset the node maps
		for (px = 0; px < 15; px++)
		{
			for (py = 0; py < 15; py++)
			{
				for (int z = 0; z < 40; z++)
				{
					Closed[px][py][z] = 0;
					Open[px][py][z] = 0;
				}
			}
		}

		// create the start node and push into list of open nodes
		n0 = new Node(xStart, yStart, 0, 0);
		n0->updatePriority(xFinish, yFinish);
		pq[pqi].push(*n0);
		Open[px][py][0] = n0->getPriority(); // mark it on the open nodes map

		while (!pq[pqi].empty())
		{

			// get the current node w/ the highest priority
			// from the list of open nodes

			n0 = new Node(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
				pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

			level = n0->getLevel();
			time = (level / 10);
			
			if (time >39)
			{
				return "Chillin";
			}
			px = n0->getxPos(); py = n0->getyPos();

			pq[pqi].pop(); // remove the node from the open list
			Open[px][py][time] = 0;
			// mark it on the closed nodes map
			Closed[px][py][time] = 1;

			// quit searching when the goal state is reached
			//if((*n0).estimate(xFinish, yFinish) == 0)
			if ((px == xFinish && py == yFinish))
			{

				// generate the path from finish to start
				// by following the directions
				string path = "";
				while (!(px == xStart && py == yStart) )
				{


					j = Grid[px][py][time];
					c = '0' + (j + dir / 2) % dir;
					path = c + path;
					px += dx[j];
					py += dy[j];

					paths[px][py][time] = 1;
					paths[px][py][time + 1] = 1;
					paths[px][py][time - 1] = 1;

					paths[px + 1][py][time] = 1;
					paths[px + 1][py][time + 1] = 1;
					paths[px + 1][py][time - 1] = 1;

					paths[px - 1][py][time] = 1;
					paths[px - 1][py][time + 1] = 1;
					paths[px - 1][py][time - 1] = 1;

					paths[px][py - 1][time] = 1;
					paths[px][py - 1][time + 1] = 1;
					paths[px][py - 1][time - 1] = 1;

					paths[px][py + 1][time] = 1;
					paths[px][py + 1][time + 1] = 1;
					paths[px][py + 1][time - 1] = 1;

					time--;
					
				}

				// garbage collection
				delete n0;
				// empty the leftover nodes
				while (!pq[pqi].empty()) pq[pqi].pop();
				
				return path;
			}

			// generate moves (child nodes) in all possible directions
			for (i = 0; i < dir; i++)
			{
				xdx = px + dx[i]; ydy = py + dy[i];

				if (!(xdx < 0 || xdx>15 - 1 || ydy < 0 || ydy>15 - 1 || Grid[xdx][ydy][time] == 0
					|| Closed[xdx][ydy][time] == 1) && paths[xdx][ydy][time] != 1)
				{
					// generate a child node
					m0 = new Node(xdx, ydy, n0->getLevel(),
						n0->getPriority());
					m0->nextLevel(i);
					m0->updatePriority(xFinish, yFinish);

					// if it is not in the open list then add into that
					if (Open[xdx][ydy][time] == 0)
					{
						Open[xdx][ydy][time + 1] = m0->getPriority();
						pq[pqi].push(*m0);
						// mark its parent node direction
						Grid[xdx][ydy][time + 1] = (i + dir / 2) % dir;
					}
					else if (Open[xdx][ydy][time] > m0->getPriority())
					{
						// update the priority info
						Open[xdx][ydy][time + 1] = m0->getPriority();
						// update the parent direction info
						Grid[xdx][ydy][time + 1] = (i + dir / 2) % dir;

						// replace the node
						// by emptying one pq to the other one
						// except the node to be replaced will be ignored
						// and the new node will be pushed in instead
						while (!(pq[pqi].top().getxPos() == xdx &&
							pq[pqi].top().getyPos() == ydy))
						{
							pq[1 - pqi].push(pq[pqi].top());
							pq[pqi].pop();
						}
						pq[pqi].pop(); // remove the wanted node

									   // empty the larger size pq to the smaller one
						if (pq[pqi].size() > pq[1 - pqi].size()) pqi = 1 - pqi;
						while (!pq[pqi].empty())
						{
							pq[1 - pqi].push(pq[pqi].top());
							pq[pqi].pop();
						}
						pqi = 1 - pqi;
						pq[pqi].push(*m0); // add the better node instead
					}
					else delete m0; // garbage collection
				}
			}
			delete n0; // garbage collection

		}
		return "9"; // no route found
	}
	

string Pathfind::pathFind(const float & xStart, const float & yStart, const float & xFinish, const float & yFinish)
{
	
	static priority_queue<Node> pq[2]; // list of open (not-yet-tried) nodes
	static int pqi; // pq index
	static Node* n0;
	static Node* m0;
	int i;
	int j;
	int px;
	int py;
	int xdx;
	int ydy;
	

	static char c;
	pqi = 0;
	


	// reset the node maps
	for (px = 0; px < 15; px++)
	{
		for (py = 0; py < 15; py++)
		{
			for (int z = 0; z < 40; z++)
			{
				Closed[px][py][z] = 0;
				Open[px][py][z] = 0;
			}
		}
	}

	// create the start node and push into list of open nodes
	n0 = new Node(xStart, yStart, 0, 0);
	n0->updatePriority(xFinish, yFinish);
	pq[pqi].push(*n0);
	Open[px][py][0] = n0->getPriority(); // mark it on the open nodes map

	while (!pq[pqi].empty())
	{

		// get the current node w/ the highest priority
		// from the list of open nodes

		n0 = new Node(pq[pqi].top().getxPos(), pq[pqi].top().getyPos(),
			pq[pqi].top().getLevel(), pq[pqi].top().getPriority());

		

		px = n0->getxPos(); py = n0->getyPos();

		pq[pqi].pop(); // remove the node from the open list
		Open[px][py][0] = 0;
		// mark it on the closed nodes map
		Closed[px][py][0] = 1;

		// quit searching when the goal state is reached
		//if((*n0).estimate(xFinish, yFinish) == 0)
		if ((px == xFinish && py == yFinish))
		{

			// generate the path from finish to start
			// by following the directions
			string path = "";
			while (!(px == xStart && py == yStart))
			{


				j = Grid[px][py][0];
				c = '0' + (j + dir / 2) % dir;
				path = c + path;
				px += dx[j];
				py += dy[j];
				
			}

			// garbage collection
			delete n0;
			// empty the leftover nodes
			while (!pq[pqi].empty()) pq[pqi].pop();
			
			return path;
		}

		// generate moves (child nodes) in all possible directions
		for (i = 0; i < dir; i++)
		{
			xdx = px + dx[i]; ydy = py + dy[i];

			if (!(xdx < 0 || xdx>15 - 1 || ydy < 0 || ydy>15 - 1 || Grid[xdx][ydy][0] == 0
				|| Closed[xdx][ydy][0] == 1))
			{
				// generate a child node
				m0 = new Node(xdx, ydy, n0->getLevel(),
					n0->getPriority());
				m0->nextLevel(i);
				m0->updatePriority(xFinish, yFinish);

				// if it is not in the open list then add into that
				if (Open[xdx][ydy][0] == 0)
				{
					Open[xdx][ydy][0] = m0->getPriority();
					pq[pqi].push(*m0);
					// mark its parent node direction
					Grid[xdx][ydy][0] = (i + dir / 2) % dir;
				}
				else if (Open[xdx][ydy][0] > m0->getPriority())
				{
					// update the priority info
					Open[xdx][ydy][0] = m0->getPriority();
					// update the parent direction info
					Grid[xdx][ydy][0] = (i + dir / 2) % dir;

					// replace the node
					// by emptying one pq to the other one
					// except the node to be replaced will be ignored
					// and the new node will be pushed in instead
					while (!(pq[pqi].top().getxPos() == xdx &&
						pq[pqi].top().getyPos() == ydy))
					{
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pq[pqi].pop(); // remove the wanted node

								   // empty the larger size pq to the smaller one
					if (pq[pqi].size() > pq[1 - pqi].size()) pqi = 1 - pqi;
					while (!pq[pqi].empty())
					{
						pq[1 - pqi].push(pq[pqi].top());
						pq[pqi].pop();
					}
					pqi = 1 - pqi;
					pq[pqi].push(*m0); // add the better node instead
				}
				else delete m0; // garbage collection
			}
		}
		delete n0; // garbage collection

	}
	return "90"; // no route found
	}
	

void Pathfind::UpdateMap(int _Grid[15][15])
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			for (int z = 0; z < 40; z++)
			{
				if (_Grid[i][j] == 23)
				{
					Grid[j][i][z] = 0;
				}
				else
				{
					Grid[j][i][z] = 1;
				}
			}
		}
	}
}

void Pathfind::resetPaths()
{
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			for (int z = 0; z < 40; z++)
			{
				{
					paths[j][i][z] = 0;
				}
			}
		}
	}
}

Pathfind::Pathfind()
{
}


