var shortestPathBinaryMatrix = function(grid) {
    let i=0
    let j=0
    if (!isValid(grid,i,j)) return -1
    let steps = 1;
    let queue = [[i,j,steps]]
    grid[0][0] =1

    while (queue.length) {
        [i,j,steps] = queue.pop()
        if (i===grid.length-1 && j===grid[i].length-1) return steps

        //eight directional
        let actionSpace = [[i+1,j+1],[i,j+1],[i+1,j],[i-1,j+1],[i+1,j-1],[i-1,j],[i,j-1],[i-1,j-1]]
        for ([i,j] of actionSpace) {
            if (isValid(grid,i,j)) {
                grid[i][j] =1
                queue.unshift([i,j,steps+1])
            }
        }
    }
    return -1
};

let isValid = (grid,i,j) => {
    return i>=0 &&
        i<grid.length &&
        j>=0 &&
        j<grid[i].length &&
        grid[i][j] === 0
}
