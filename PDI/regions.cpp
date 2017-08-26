#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main(int argc, char const *argv[])
{	
Mat image;
int P1_X,P1_Y,P2_X,P2_Y,largura,altura,aux_x,aux_y;
image=imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
if(!image.data){
	cout<<"nao abriu biel.png"<<endl;
}
Size tamanho = image.size();
namedWindow("janela",WINDOW_AUTOSIZE);
altura = tamanho.height;
largura = tamanho.width;
cout<<"ALTURA: "<< altura<<" LARGURA: " << largura<<endl;
cout<<"Digite as coordenadas (x,y) do primeiro ponto:"<<endl;
cin >>P1_X;
cin>>P1_Y;
if (P1_X > altura or P1_Y >altura)
{
	cout<<"Por favor, redigite as coordenadas (x,y) do primeiro ponto:"<<endl;
	cin>>P1_X;
	cin>>P1_Y;
}
cout<<"Digite as coordenadas (x,y) do segundo ponto :"<<endl;
cin >>P2_X;
cin>>P2_Y;
if (P2_X > largura or P2_Y > largura)
{
	cout<<"Por favor, redigite as coordenadas (x,y) do segundo ponto:"<<endl;
	cin>>P2_X;
	cin>>P2_Y;	
}
//teste sobre os valores de p1 e p2 
	if(P1_X < P2_X and P1_Y <P2_Y){
		for(int i= P1_X;i<=P2_X;i++){
			for (int j=P1_Y;j<=P2_Y;++j){
			image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
			}
		}
		imshow("janela",image);
		waitKey();
	}
	else if(P1_X > P2_X and P1_Y <P2_Y){
		for(int i= P2_X;i<=P1_X;i++){
			for (int j=P1_Y;j<=P2_Y;++j){
			image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
			}
		}
		imshow("janela",image);
		waitKey();
	}
	//testes que requerem atualizacao
	else if (P1_X < P2_X and P1_Y > P2_Y){
		aux_x=P1_X;
		P1_X=P2_X;
		P2_X=aux_x;
		aux_y=P1_Y;
		P1_Y=P2_Y;
		P2_Y=aux_y;
		for(int i= P2_X;i<=P1_X;i++){
			for (int j=P1_Y;j<=P2_Y;++j){
			image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
			}
		}
		imshow("janela",image);
		waitKey();	
	}
	else if(P1_X > P2_X and P1_Y >P2_Y){
		aux_x=P1_X;
		P1_X=P2_X;
		P2_X=aux_x;
		aux_y=P1_Y;
		P1_Y=P2_Y;
		P2_Y=aux_y;
		for(int i= P1_X;i<=P2_X;i++){
			for (int j=P1_Y;j<=P2_Y;++j){
			image.at<uchar>(i,j)=255-image.at<uchar>(i,j);
			}
		}
		imshow("janela",image);
		waitKey();
	}	
else{
	cout<<"Infelizmente voce nao escolheu pontos em vertices opostos."<<endl;
}
return 0;
}	
