//time: O(m*n)
Array.prototype.peek = function () {
    return this[this.length-1]
}

var maximalRectangle = function(matrix) {
  for (let i=0; i<matrix.length; i++) {
      for (let j=0; j<matrix[i].length; j++) {
          matrix[i][j] = parseInt(matrix[i][j],10)
          if (i>0 && matrix[i][j] !== 0) {
              matrix[i][j] += matrix[i-1][j] 
          }
      }
  }

  //from biggest rectangle in a histogram
  //using monotonic stack
  let maxRec = 0
  for (let i=0; i<matrix.length; i++) {
      let stack = [-1]
      matrix[i].push(0)
      for (let j=0; j<matrix[i].length; j++) {
          while(matrix[i][stack.peek()]>=matrix[i][j]) {
              let height = matrix[i][stack.pop()]
              let width = j - 1 - stack.peek()
              maxRec = Math.max(maxRec, height*width)
          }
          stack.push(j)
      }
  }
  return maxRec
};
