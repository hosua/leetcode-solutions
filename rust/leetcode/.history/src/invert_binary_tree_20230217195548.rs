// Definition for a binary tree node.
#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
  pub val: i32,
  pub left: Option<Rc<RefCell<TreeNode>>>,
  pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
  #[inline]
  pub fn new(val: i32) -> Self {
    TreeNode {
      val,
      left: None,
      right: None
    }
  }
}
use std::rc::Rc;
use std::cell::RefCell;
use std::mem::swap;
impl Solution {
    pub fn invert_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        pub fn helper(node: &Option<Rc<RefCell<TreeNode>>>){
            if let Some(n) = node {
                let n = n.borrow();
                helper(&n.left);
                helper(&n.right);
            }
        }
        if let Some(n) = root {
            let n = n.borrow();    
        }

        root
    }
}