# AC - topological sort + 01Knapsack
import sys

B = 0
did = {}
dishes = []
prestiges = []
costs = []
recipes_from = {}
opt = []

def topological_sort():
	# los platos que tienen in_degree a 0, platos base, en este caso solo hay uno. 
	in_degree = {}
	for x, neighbors in recipes_from.items():
		in_degree.setdefault(x, 0)
		for n in neighbors:
			in_degree[n[0]] = in_degree.get(n[0], 0) + 1
	#anadimos los que tienen degree 0 al set
	empty = {v for v, count in in_degree.items() if count == 0}

	topological = []
	#kahn algorithm
	while empty:
		v = empty.pop() #empty es un set!
		
		topological.append(v)

		for neighbor in recipes_from.get(v, []):
			in_degree[neighbor[0]] -= 1
			if in_degree[neighbor[0]] == 0:
				empty.add(neighbor[0]) 

	# nos aseguramos que no hay un ciclo
	assert len(topological) == len(dishes)
	print(topological)
	return topological

# nos quedamos con el menor coste y el mayor prestigio para cada nodo
def compute_costs(toposort):
	for dish in toposort:
		if dish in recipes_from:
			for recipe in recipes_from[dish]:
				# buscamos el camino mas corto
				new_cost = costs[dish] + recipe[1]
				if new_cost < costs[recipe[0]]:
					costs[recipe[0]] = new_cost
					prestiges[recipe[0]] = prestiges[dish] + recipe[2]
				# si se repiten el coste miramos el mejor prestigio
				elif new_cost == costs[recipe[0]]:
					new_prest = prestiges[dish] + recipe[2]
					if new_prest > prestiges[recipe[0]]:
						prestiges[recipe[0]] = new_prest

def read_input():
	B, N = int(sys.stdin.readline()), int(sys.stdin.readline())
	index = 0
	for i in range(N):
		dish_to, dish_from, _, cost, prestige = [ingredient for ingredient in sys.stdin.readline().strip().split()]
		cost, prestige = int(cost), int(prestige)

		#ids para cada plato - anadimos los costes y prestigio - anadimos platos
		if dish_from not in did:
			did[dish_from] = index
			costs.append(0)
			prestiges.append(0)
			dishes.append(dish_from)
			index += 1

		if dish_to not in did:
			did[dish_to] = index
			costs.append(int(1e9))
			prestiges.append(0)
			dishes.append(dish_to)
			index += 1
		else: #el plato se repite por lo que el coste lo ponemos a INF
			dish = did[dish_to]
			costs[dish] = int(1e9)
		#lista adyacente con los platos origen: (destino, coste, prestigio)
		recipes_from.setdefault(did[dish_from], [])
		# (to, cost, prestige)
		recipes_from[did[dish_from]].append((did[dish_to], cost, prestige))
	
	return B

#01-knapsack clasico
def knapsack(B):
	opt.append([])
	#primera fila a 0's
	for j in range(B+1): opt[0].append(0)
	for i in range(1, len(dishes) + 1):
		opt.append([])
		for w in range(B+1):
			if costs[i-1] <= w:
				opt[i].append(max(opt[i-1][w-costs[i-1]] + prestiges[i-1], opt[i-1][w]))
			else:
				opt[i].append(opt[i-1][w])

	print (opt[len(dishes)][B])

# la solucion puede estar antes en la matriz, por eso se busca el indice menor
def reconstruct_solution(B):
	nitems = len(dishes)
	prev = opt[nitems][B]
	for i, elem in reversed(list(enumerate(opt[nitems]))):
		if prev != elem:
			print(i+1)
			break
	else:
		print(0)
	
while True:	
	try:
		B = read_input()
		compute_costs(topological_sort())
		knapsack(B)
		reconstruct_solution(B)
		did.clear(), dishes.clear(), prestiges.clear(), costs.clear(), recipes_from.clear(), opt.clear()
	except:
		sys.exit(0)
