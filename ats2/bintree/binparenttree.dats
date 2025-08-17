#include "share/atspre_staload.hats"


datatype tree = 
| Empty of ()
| Node of (int, tree, tree, tree)


datatype tree_with_parent = 
| EmptyWithParent of ()
| NodeWithParent of (int, tree, tree, int)

extern fun tree_insert (t: tree, value: int): tree
extern fun tree_print_inorder (t: tree): void


implement tree_insert (t, value) =
   case+ t of
  | Empty() => Node(value, Empty(), Empty(), Empty())
  | Node(v, parent, left, right) =>
     if value < v then
      Node(v, parent, tree_insert(left, value), right)
    else if value > v then
      Node(v, parent, left, tree_insert(right, value))
    else
      t


implement tree_print_inorder(t) =
    case+ t of
    | Empty() => ()
    | Node(v, parent, left, right) => let
    val () = tree_print_inorder(left)
    val () = print(v)
    val () = print(" ")
    val () = tree_print_inorder(right)
  in
    ()
  end

extern fun build_tree (): tree


implement build_tree () = let
  val t0 = Empty()
  val t1 = tree_insert(t0, 50)
  val t2 = tree_insert(t1, 60)
  val t3 = tree_insert(t2, 30)
in
  t3
end

implement main0 () = let
  val tree = build_tree()

  val () = println!("Inorder traversal:")
  val () = tree_print_inorder(tree)
  val () = println!()
in
  ()
end