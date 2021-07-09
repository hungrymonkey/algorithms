const Node = struct {
    val: i32,
    p: ?*Node,
    l: ?*Node,
    r: ?*Node,
};

const BST = struct {
    root: ?*Node,
};

fn bin_insert(b: *BST, v: i32) *Node {
    if (b.root == null) {
        b.root = Node{ .val = v, .p = null, .l = null, .r = null };
        return b.root;
    } else {
        return node_insert(b.root, v);
    }
}
fn node_insert(curr: *Node, v: i32) *Node {}
