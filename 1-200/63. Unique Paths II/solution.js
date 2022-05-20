var uniquePathsWithObstacles = function(obstacleGrid) {
  let arr = obstacleGrid[0]
  let prev = 1
  //first row
  for (let j=0; j<arr.length; j++) {
    if (arr[j] === 0) {
      arr[j] += prev
    } else {
      arr[j] = 0 
    }
    prev = arr[j]
  }
  
  //the rest of the rows
  prev = 0
  for (let i=1; i<obstacleGrid.length; i++) {
    for (let j=0; j<arr.length; j++) {
      if (obstacleGrid[i][j]===0) {
        arr[j] += prev
      } else {
        arr[j] = 0
      }
      prev = arr[j]
    }
    prev = 0
  }

  return arr.pop()
};
