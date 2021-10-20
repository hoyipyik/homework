present=importdata('q1_3.txt');
E=mean(present);
D=var(present);
cdfplot(present);
figure;
histogram(present,100,'Normalization','pdf')
 ksdensity(present);