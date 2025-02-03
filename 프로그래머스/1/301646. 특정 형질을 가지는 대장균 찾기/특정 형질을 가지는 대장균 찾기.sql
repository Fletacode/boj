select count(*) as count
from ECOLI_DATA as A
where (A.GENOTYPE & 2) = 0 and ((A.GENOTYPE & 1) = 1 or (A.GENOTYPE & 4) = 4)
