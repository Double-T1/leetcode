var updateMatrix = function(mat) {
    for (let i=0; i<mat.length; i++) {
        for (let j=0; j<mat[i].length; j++) {
            if (mat[i][j] === 0) continue
            mat[i][j] = Number.MAX_SAFE_INTEGER
            if (i>0) mat[i][j] = Math.min(mat[i][j],mat[i-1][j]+1)
            if (j>0) mat[i][j] = Math.min(mat[i][j],mat[i][j-1]+1)
        }
    }
    for (let i=mat.length-1; i>=0; i--) {
        for (let j=mat[i].length-1; j>=0; j--) {
            if (mat[i][j] === 0) continue
            if (i<mat.length-1) mat[i][j] = Math.min(mat[i][j],mat[i+1][j]+1)
            if (j<mat[i].length-1) mat[i][j] = Math.min(mat[i][j],mat[i][j+1]+1)
        }
    }
    return mat
};
