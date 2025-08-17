#include "share/atspre_staload.hats"


datatype tree = 
| Empty of ()
| Node of (int, tree, tree, tree)


datatype tree_with_parent = 
| EmptyWithParent of ()
| NodeWithParent of (int, tree, tree, int)

extern fun tree_insert (t: tree, value: int): tree
extern fun tree_print_inorder (t: tree): void
extern fun tree_print_node (t: tree): void
extern fun tree_find(t: tree, value: int): tree


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

implement tree_find(t, value) = 
   case+ t of
   | Empty() => Empty()
   | Node(v, parent, left, right) =>
     if value < v then
        tree_find(left, value)
     else if value > v then
        tree_find(right, value)
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

implement tree_print_node(t) =
   case+ t of
    | Empty() => ()
    | Node(v, parent, left, right) => let
    val () = print(v)
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
  val tnode = tree_find(tree, 30)
  val () = tree_print_node(tnode)
  val () = println!()
in
  ()
end