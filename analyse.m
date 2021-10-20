present=importdata('q2.txt');
E=mean(present);
D=var(present);
cdfplot(present);
figure;
histogram(present,100,'Normalization','pdf')

%% ksdensity(present);