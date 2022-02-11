const std = @import("std");

const Node = struct {
    val: i32,
    l: ?*Node,
    r: ?*Node,
    
    pub fn insert(self: *Node, v: i32) ?*Node {
        self.l = &Node{ .val = v, .l = null, .r = null };
        return null;
    }
    pub fn print(self: *Node) anyerror!void {
        //if(self.l != null) try self.l.?.print();
        const stdout = std.io.getStdOut().writer();
        try stdout.print("Hello, {d}!\n", .{self.val});
        //if(self.r != null) try self.r.?.print();
    }
};

pub const BST = struct {
    root: ?*Node,

    pub fn insert(self: *BST, v: i32) ?*Node {
        if (self.root == null) {
            self.root = &Node{ .val = v, .l = null, .r = null };
            return self.root;
        } 
        return self.root.?.insert(v);
    }
    pub fn print(self: *BST) anyerror!void {
        try self.root.?.print();
    }
};

pub fn bin_insert(b: *BST, v: i32) *Node {
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


