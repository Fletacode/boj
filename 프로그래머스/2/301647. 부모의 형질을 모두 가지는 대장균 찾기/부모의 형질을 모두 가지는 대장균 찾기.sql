select B.id, B.genotype, A.genotype as parent_genotype
from ECOLI_DATA as A
inner join ECOLI_DATA as B
on A.id = B.parent_id
where (A.genotype & B.genotype) = A.genotype; 