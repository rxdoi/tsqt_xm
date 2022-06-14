#include<bits/stdc++.h>
using namespace std;

const int N=35;
const int oo=(1<<29)-1;

int tot[4]={0,0,29,35};
string str[4][N]={
{},
{},
{"四相决6","四相决7","四相决8","四相决9","四相决10","唤灭破6","唤灭破7","唤灭破8","唤灭破9","唤灭破10","恸地神咒6","恸地 神咒7","恸地神咒8","恸地神咒9","摄魂咒6","摄魂咒7","摄魂咒8","摄魂咒9","摄魂咒10","魅惑术6","魅惑术7","魅惑术8","魅惑术9","魅惑术10","玄天心火4","玄天心火5","玄天心火6","玄天心火7","玄天心火8"},
{"慈悲咒6","慈悲咒7","慈悲咒8","慈悲咒9","慈悲咒10","沉水润心6","沉水润心7","沉水润心8","沉水润心9","沉水润心10","仙音化雨6","仙音化雨7","仙音化雨8","仙音化雨9","仙音化雨10","天地极乐6","天地极乐7","天地极乐8","天地极乐9","天地极乐10","圣灵附体6","圣灵附体7","圣灵附体8","圣灵附体9","圣灵附体10","昊天罡气6","昊天罡气7","昊天罡气8","昊天罡气9","昊天罡气10","如履薄冰4","如履薄冰5","如履薄冰6","如履薄冰7","如履薄冰8"}
};

int A[4][N]={
{},
{},
{114,150,187,232,287,100,131,165,202,252,706,884,1080,1276,95,125,156,193,239,114,150,187,232,287,280,346,425,515,619},
{95,125,156,193,239,373,470,589,720,886,114,150,187,232,287,95,125,156,193,239,114,150,187,232,287,95,125,156,193,239,280,346,425,515,619}
};

vector<string> Vs;
vector<int> Vi;
int B[8];
int mp;
int rat;
int fir,x,zhi;
int ansx,ansn,ansi,ansj,ansk,ansr;

int main(){
	system("chcp 65001");
	printf("你的蓝量:");
	scanf("%d",&mp);
	printf("你的职业（1侠客，2刺客，3术士，4修真）:");
	scanf("%d",&zhi);
	zhi--;
	printf("仙气护体耗蓝:");
	scanf("%d",&fir);
	for (int i=0;i<tot[zhi];i++){
		Vs.push_back(str[zhi][i]);
		Vi.push_back(A[zhi][i]);
	}
	if (zhi!=3){
		for (int i=10;i<15;i++){
			Vs.push_back(str[3][i]);
			Vi.push_back(zhi==2?A[3][i]*2:A[3][i]*3);
		}
	}
	int n=Vs.size();
	for (int i=0;i<n;i++) printf("%d ",Vi[i]);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++) if (Vi[i]+Vi[j]+Vi[k]+fir==1800){
				for (rat=0;rat<99;rat++){
					int mn=oo;
					int mx=-oo;
					for (int st=4001;st<5000;st++){
						B[0]=st;
						B[1]=B[0]-fir;
						B[2]=B[1]+450;
						B[3]=B[2]+450;
						B[4]=B[3]-Vi[i];
						B[5]=B[4]-Vi[j];
						B[6]=B[5]+450;
						B[7]=B[6]+450;
						if (B[0]<=1.0*rat/100*mp || B[0]<=4000) continue;
						if (B[1]> 1.0*rat/100*mp || B[1]>=4000) continue;
						if (B[2]> 1.0*rat/100*mp || B[2]>=4000) continue;
						if (B[3]<=1.0*rat/100*mp || B[3]<=4000) continue;
						if (B[4]<=1.0*rat/100*mp || B[4]<=4000) continue;
						if (B[5]> 1.0*rat/100*mp || B[5]>=4000) continue;
						if (B[6]> 1.0*rat/100*mp || B[6]>=4000) continue;
						if (B[7]<=1.0*rat/100*mp || B[7]<=4000) continue;
						mn=min(mn,st);
						mx=max(mx,st);
					}
					if (mx-mn>ansx-ansn){
						ansx=mx;
						ansn=mn;
						ansi=i;
						ansj=j;
						ansk=k;
						ansr=rat;
					}
				}
			}
		}
	}
	if (ansx==ansn){
		printf("抱歉，没有找到方案，请调整蓝量试试。\n");
		return 0;
	} else{
		printf("回蓝比例: %d %%，设置大碗茶\n",ansr);
		printf("初始蓝量: [%d,%d]\n",ansn,ansx);
		printf("第1回合: 仙气\n");
		printf("第2回合: 任意\n");
		printf("第3回合: 任意\n");
		printf("第4回合: %s\n",Vs[ansi].c_str());
		printf("第5回合: %s\n",Vs[ansj].c_str());
		printf("第6回合: 任意\n");
		printf("第7回合: 任意\n");
		printf("第8回合: %s\n",Vs[ansk].c_str());
	}
}