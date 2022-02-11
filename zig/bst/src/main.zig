const std = @import("std");

const bst = @import("bst");

pub fn main() anyerror!void {
    var tree: bst.BST = .{ .root = null };

    _ = tree.insert(5);
    try tree.print();
    if (tree.root == null) 
        std.log.info("empty tree", .{});
    std.log.info("All your codebase are belong to us.", .{});
}

test "basic test" {
    try std.testing.expectEqual(10, 3 + 7);
}
