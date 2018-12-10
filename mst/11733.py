import sys, heapq
from queue import PriorityQueue as pq

def solution():
	global total
	total = 0
	for key, value in graph.items():
		if key not in visited:
			total += prim(key)
	return total

def prim(origen):
	global aeropuertos, visited
	mst = coste_aeropuerto
	aeropuertos += 1
	#pq = [(coste, destino) for coste, destino in graph[origen]]
	q = pq()
	for coste, destino in graph[origen]:
	 	q.put((coste, destino))
	#visited.add(origen)
	visited[origen] = True
	#heapq.heapify(pq)

	while not q.empty():
		#coste, destino = heapq.heappop(pq)
		coste, destino = q.get()
		if destino not in visited:
			#visited.add(destino)
			visited[destino] = True
			if coste >= coste_aeropuerto:
				mst += coste_aeropuerto
				aeropuertos += 1
			else:
				mst += coste
			for cost, next_ in graph[destino]:
				if next_ not in visited:
					#heapq.heappush(pq, (cost, next_))
					q.put((cost, next_))
				else: continue
		else: continue

	return mst


t = int(sys.stdin.readline())
for cases in range(t):
	ciudades, calles, coste_aeropuerto = [int(i) for i in sys.stdin.readline().split()]
	graph = {}
	for i in range(ciudades):
		graph.setdefault(i+1, [])
	
	for i in range(calles):
		origen, destino, coste = [int(i) for i in sys.stdin.readline().split()]
		
		graph[origen].append((coste, destino))
		graph[destino].append((coste, origen))
	aeropuertos, total = 0, 0
	#visited = set([])
	visited = {}
	total += solution()
	print('Case #%d: %d %d' % (cases+1, total, aeropuertos))
	

