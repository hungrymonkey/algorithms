const std = @import("std");

const Node = struct {
    val: i32,
    l: ?*Node,
    r: ?*Node,
};

const BST = struct {
    root: ?*Node,
};

fn bin_insert(b: *BST, v: i32) *Node {
    if (b.root == null) {
        b.root = Node{ .val = v, .l = null, .r = null };
        return b.root;
    } else {
        return node_insert(b.root, v);
    }
}
fn node_insert(curr: *Node, v: i32) *Node {
    if (curr == null) {
        curr = Node{ .val = v, .l = null, .r = null };
        return curr;
    }
    if (curr.val < v) {
        return node_insert(curr.r, v);
    } else {
        return node_insert(curr.l, v);
    }
}
fn print_bin(b: *BST) void {
    if(b == null) return;
    print_bin(b.l);
    try stdout.print("Hello, {d}!\n", .{b.val});
    print_bin(b.r);
}