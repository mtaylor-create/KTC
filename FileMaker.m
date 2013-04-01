for i=1:169
    fileList = dir(num2str(i));
    i
    for j=1:length(fileList);
        if (fileList(j).isdir == 0);
            fSource=strcat(num2str(i),'/',fileList(j).name);
            
            mData = fileList(j).name;
            
            [kidName, mData] = strtok(mData,'_');
            [kidAge, mData] = strtok(mData,'_');
            
            fid = fopen(fSource);
            oid = fopen(strcat(num2str(i),'.txt'),'w');
            
            fwrite(oid,strcat('A message from',32,kidName));
            fwrite(oid,13);
            fwrite(oid,strcat('Age:',32,kidAge));
            fwrite(oid,13);


            tline = fgetl(fid);
            fStr = '';
            while ischar(tline)

               while length(tline)>32
                    tline=strtrim(tline);
                    idx=min(33,length(tline));
                    while and(isspace(tline(idx))==0,idx>2);
                        idx=idx-1;
                    end
                   
                    cline=tline(1:idx-1);
                    tline=tline(idx:end);
                    cline=strrep(cline,9,32);
                    fwrite(oid,cline);
                    fwrite(oid,13);
               end
               tline=strtrim(tline);
               fwrite(oid,tline);
               fwrite(oid,13);
               
               tline = fgetl(fid);
              
            end
            
            fwrite(oid,13);
            fwrite(oid,'Installation by Mike Taylor');
            fwrite(oid,13);
            fwrite(oid,'Go to www.hear-me.net for more!');
            fwrite(oid,13);
            
            fclose(fid);
            fclose(oid);
            
            
            
            %fDest=strcat(num2str(i),'.txt');
            %copyfile(fSource,fDest);
        end
    end
end
            