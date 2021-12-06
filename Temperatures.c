/*************************************************************************
        Copyright © 2021 Konstantinidis Konstantinos

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
*************************************************************************/
#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <math.h>

int main(){
    double temperature[5][3], natavg, average[5], sum, devnat[5][3], mdeviation[5];
    int i, j;

    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            printf("Temperature of City %d During %d 8-hour period: ",i + 1, j + 1);
            temperature[i][j] = GetReal();
        }
    }

    natavg = 0;
    for(i = 0; i < 5; i ++)
        for(j = 0; j < 3; j++)
            natavg += temperature[i][j];

    natavg = natavg / (5*3);
    printf("National average temperature: %.1f\n",natavg);
    for(i = 0; i < 5; i ++){
        sum = 0;
        for(j = 0; j < 3; j++){
            sum += temperature[i][j];
        }
        average[i] = sum / 3;
    }

    for(i = 0; i < 5; i ++)
        for(j = 0; j < 3; j++)
            devnat[i][j] = fabs(natavg - temperature[i][j]);

    for(i = 0; i < 5; i ++){
        mdeviation[i] = devnat[i][0];
        for(j = 0; j < 3; j++)
            if(mdeviation[i] < devnat[i][j])
                mdeviation[i] = devnat[i][j];
    }

    for(i = 0; i < 5; i ++)
        printf("City %d |Average temp.: %.1f| |Max deviation(from national average temp.): %.1f|\n",i + 1, average[i], mdeviation[i]);

    system("PAUSE");
}
