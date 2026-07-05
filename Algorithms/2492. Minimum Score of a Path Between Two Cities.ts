function minScore(n: number, roads: number[][]): number {
    const graph = new Map<number, Map<number, number>>();
    const connections = new Map<number, number[]>();
    for (let road of roads) {
        let x = road[0], y = road[1], z = road[2]
        if (!graph.has(x)) graph.set(x, new Map())
        if (!graph.has(y)) graph.set(y, new Map())
        if (!connections.has(x)) connections.set(x, [])
        if (!connections.has(y)) connections.set(y, [])
        
        graph.get(x)!.set(y, z)
        graph.get(y)!.set(x, z)
        connections.get(x)!.push(y)
        connections.get(y)!.push(x)
    }
    // let ans = Number.MAX_SAFE_INTEGER
    let ans = 2 ** 31 - 1
    let seen = new Set<number>()
    let dfs: number[] = []
    dfs.push(1)
    while (dfs.length) {
        let cur = dfs.pop()!
        if (seen.has(cur)) continue
        seen.add(cur)
        for (let connection of connections.get(cur) ?? []) {
            dfs.push(connection)
            // ans = Math.min(ans, graph[cur][connection])
            const w = graph.get(cur)?.get(connection)
            if (w !== undefined) {
                ans = Math.min(ans, w)
            }
        }
    }

    return ans
};