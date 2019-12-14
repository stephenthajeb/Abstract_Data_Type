int __cdecl ward(char* input)
{
  unsigned int v1; 
  int v1;
  int v3;

  scanf("%d %d",&v1,&v2); 
  if ((v2-2) != 2){
      bad_instruction();
  }
  v3 =  func4(v2, 0, 14);//Asumsikan func4 sudah terdefinisi
  if (v1 != v3){
      bad_instruction();
  }
    
  return 0;
}