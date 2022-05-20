var uniquePathsIII = function(grid) {
    let start;
    //steps includes the end and excludes the start
    let steps = 0
    for (let i=0; i<grid.length; i++) {
        for (let j=0; j<grid[i].length; j++) {
            if (grid[i][j]===1) {
                start = [i,j]
            } else if (grid[i][j]%2 === 0) {
                steps++
            }
        }
    }
    
    //backtrack the whole grid
    //we want the number of succesful trips
    return backtrack(grid,steps,start[0],start[1])
};

let backtrack = (grid,steps,i,j) => {
    if (steps === 0 && grid[i][j] === 2) {
        return 1
    } else if (steps === 0 || grid[i][j] === 2) {
        return 0
    } else {
        let count = 0
        grid[i][j] = 1
        let actionSpace = [[i+1,j],[i-1,j],[i,j+1],[i,j-1]]
        for ([i,j] of actionSpace) {
            if(isValid(grid,i,j)) count += backtrack(grid,steps-1,i,j)
        }
        grid[i][j+1] = 0
        return count
    }
}


let isValid = (grid,i,j) => {
    return i>=0 &&
        i<grid.length &&
        j>=0 &&
        j<grid[i].length &&
        grid[i][j]%2 === 0
}
