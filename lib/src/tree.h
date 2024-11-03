#ifndef TREE_SITTER_TREE_H_
#define TREE_SITTER_TREE_H_

#include "./subtree.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  const Subtree *child;
  const Subtree *parent;
  Length position;
  TSSymbol alias_symbol;
} ParentCacheEntry;

struct TSTree {
  Subtree root;
  const TSLanguage *language;
  TSRange *included_ranges;
  unsigned included_range_count;
  size_t _src_len;              /* NOTE: Added in nordlow/tree-sitter */
  char* _src_ptr;               /* NOTE: Added in nordlow/tree-sitter */
};

TSTree *ts_tree_new(Subtree root, const TSLanguage *language, const TSRange *included_ranges, unsigned included_range_count);
TSNode ts_node_new(const TSTree *tree, const Subtree *subtree, Length position, TSSymbol alias);

#ifdef __cplusplus
}
#endif

#endif  // TREE_SITTER_TREE_H_
