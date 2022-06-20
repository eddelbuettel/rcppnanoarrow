#include <Rcpp.h>

#include "arrowc.h"
extern "C" {
  void ArrowSchemaRelease(struct ArrowSchema* schema); // missing in header
}

// [[Rcpp::export]]
bool allocCheck() {
  struct ArrowSchema sch;
  ArrowErrorCode rc = 0;
  rc = ArrowSchemaInit(1, &sch);
  if (rc != ARROWC_OK) Rcpp::stop("Could not alloc");

  ArrowSchemaRelease(&sch);
  return true;
}
