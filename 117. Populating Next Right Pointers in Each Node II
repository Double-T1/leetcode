//bfs
var connect = function(root) {
    let queue = [root]
    while (queue.length) {
        let size = queue.length
        let prev;
        while (size) {
            let node = queue.pop()
            if (prev !== undefined) prev.next = node
            prev = node
            if (node.left) queue.push(node.left)
            if (node.right) queue.push(node.right)
            size--
        }
    }
    return root
};
