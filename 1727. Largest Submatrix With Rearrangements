var largestSubmatrix = function(matrix) {
    for (let i=1 ;i<matrix.length; i++) {
        for (let j=0; j<matrix[i].length; j++) {
            if (matrix[i][j] === 1) matrix[i][j] += matrix[i-1][j] 
        }
    }
    
    let max = 0
    for (let i=0; i<matrix.length; i++) {
        matrix[i].sort((a,b) => a-b)
        let len = matrix[i].length
        for (let j=0; j<len; j++) {
            max = Math.max(max,matrix[i][j]*(len-j))
        }
    }
    return max
};
