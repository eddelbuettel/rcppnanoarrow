#include <Rcpp.h>

#include "nanoarrow.h"
extern "C" {
  void ArrowSchemaRelease(struct ArrowSchema* schema); // missing in header
}

// [[Rcpp::export]]
bool allocCheck() {
  struct ArrowSchema sch;
  ArrowErrorCode rc = 0;
  rc = ArrowSchemaInit(&sch, NANOARROW_TYPE_UNINITIALIZED);
  if (rc != NANOARROW_OK) Rcpp::stop("Could not alloc");

  ArrowSchemaRelease(&sch);
  return true;
}
