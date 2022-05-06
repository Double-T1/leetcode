var addTwoNumbers = function(l1, l2) {
    let node1 = l1, node2 = l2, carry=0
    let pseudoHead =new ListNode()
    let prev = pseudoHead
    while (node1||node2||carry) {
        let total = 0
        if (node1) {
            total += node1.val
            node1 = node1.next
        }
        if (node2) {
            total += node2.val
            node2 = node2.next
        }
        if (carry) {
            total += carry
        }
        let val = total%10
        carry = (total-val)/10
        prev.next = new ListNode(val)
        prev = prev.next
    }
    return pseudoHead.next
};
