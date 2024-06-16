def evaluate(outputfolder):
    total=0
    flag=0
    for myfile in files_add:
        like=[]
        dislike=[]
        counter=0
        person=0
        output_filename=outputfolder+myfile[8:]
        with open(output_filename, "r") as file:
            output=file.readline()
        output=output.split(" ")
        output=output[1:]
        with open(myfile, "r") as file:
            while True:
                line=file.readline()
                if line=="":break
                if counter!=0:
                    line=line.replace("\n","")
                    line=line.split(" ")
                        
                        
                    if counter%2!=0:
                        temp1=1
                        for i in line[1:]:
                            if i not in output:
                                temp1=0
                                
                    if counter%2==0:
                        temp2=1
                        for i in line[1:]:
                            if i in output:
                                temp2=0  
                        
                        person+=(temp1 and temp2)                                 
                
                counter+=1
        print('%-15s %-30s %-10s %-10s' % ("File name: ",str(myfile)," score:",  str(person) ))
            


        total=total+person
    print(f'Total score: {total}')

files_add = ['./input/a_an_example.in.txt',
 './input/b_basic.in.txt',
 './input/c_coarse.in.txt',
 './input/d_difficult.in.txt',
 './input/e_elaborate.in.txt']
evaluate(outputfolder='output/')