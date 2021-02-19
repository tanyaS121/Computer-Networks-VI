#include<stdio.h>
#include<string.h>
#define TEXTSIZE 3
#define MAXFRAME 100
char str[TEXTSIZE * MAXFRAME];

struct frame{ 
    char text[TEXTSIZE];
    int seqNo;
    }
    frm[MAXFRAME], shuff[MAXFRAME];
    int assign_seqNo(){
        int k=0,i,j;
        for(i=0; i < strlen(str); k++){
            frm[k].seqNo = k;
            for(j=0; j<TEXTSIZE && str[i]!='\0'; j++)
            frm[k].text[j] = str[i++];
        }
        printf("\nSequence number assigned: \n");
        for(i=0; i < k; i++)
        printf("%d:%s   ",i,frm[i].text);
        return k;
    }

void generate(int *ranAry, const int limit){
    int r, i=0, j;
    while(i < limit){
        r = random() % limit;
        for(j=0; j < i; j++)
        if( ranAry[j]== r)
        break;
        if(i==j)ranAry[i++]= r;
        } 
    }

void shuffle( const int frames){
    int i, k=0, ranAry[frames];
    generate(ranAry, frames);
    for(i=0; i<frames; i++)
    shuff[i] = frm[ranAry[i]];
    printf("\n\nNow shuffled: \n");
    for(i=0; i<frames; i++)
    printf("%d:%s   ",shuff[i].seqNo,shuff[i].text);
    }

void bsort(const int frames){
    int i,j,flag=1;
    struct frame hold;
    for(i=0; i < frames-1 && flag==1; i++){
        flag=0;
        for(j=0; j < frames-1-i; j++)
        if(shuff[j].seqNo > shuff[j+1].seqNo){
            hold = shuff[j];
            shuff[j] = shuff[j+1];
            shuff[j+1] = hold;
            flag=1;
        }
    }
}

int main(){
    int frames,i;
    printf("ENTER MESSAGE...\n");
    gets(str);
    frames = assign_seqNo();
    shuffle(frames);
    bsort(frames);
    printf("\n\nAFTER SORTING...\n");
    for(i=0;i<frames;i++)
    printf("%s",shuff[i].text);
    printf("\n\n");
}