var longestIncreasingPath = function(matrix) {
    let LIP = new Array(matrix.length)
        .fill()
        .map(() => new Array(matrix[0].length).fill(0)) 

    let max = 0
    for (let i=0; i<matrix.length; i++) {
        for (let j=0; j<matrix[i].length; j++) {
            if(LIP[i][j] === 0) max= Math.max(dfs(matrix,i,j,LIP),max)
        }
    }
    return max
};

let dfs = (grid,i,j,LIP) => {
    if (LIP[i][j] !== 0) return LIP[i][j]

    let max = 1
    let actionSpace = [[i+1,j],[i-1,j],[i,j+1],[i,j-1]]
    for (const [m,n] of actionSpace) {
        if (isValid(grid,m,n) && grid[m][n] > grid[i][j]) {
            max = Math.max(dfs(grid,m,n,LIP)+1,max)
        }
    }
    LIP[i][j] = max
    return max
}

let isValid = (grid,i,j) => {
    return i>=0 &&
        i<grid.length &&
        j>=0 &&
        j<grid[i].length
}
