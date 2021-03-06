#include "saint.h"

/**************************************************************/
/*        computing expected counts in log scale (s/ns)       */
/**************************************************************/

/*************************/
/*    all interactions   */
/*************************/
void compute_lambda_true_all(PARAM *param, PRIOR *prior, DATA *data) {
  int i;
  for(i=0;i<data->ninter;i++) {
    // data->c[i]
    // param->lambda_true[i] = data->l[i] + data->c[i] + param->beta0 + param->alpha_prey[data->i2p[i]];
    param->lambda_true[i] = data->l[i] + param->beta0 + param->alpha_prey[data->i2p[i]] + param->alpha_IP[data->i2IP[i]];
    if(NORMALIZE) param->lambda_true[i] += data->c[i];
  }
}

void compute_lambda_false_all(PARAM *param, PRIOR *prior, DATA *data) {
  int i;
  for(i=0;i<data->ninter;i++) {
    param->lambda_false[i] = data->l[i] + param->betac + param->mu[data->i2p[i]];
    if(NORMALIZE) param->lambda_false[i] += data->c[i];
  }
}

void compute_lambda_all(PARAM *param, PRIOR *prior, DATA *data) {
  compute_lambda_true_all(param, prior, data);
  compute_lambda_false_all(param, prior, data);
}
