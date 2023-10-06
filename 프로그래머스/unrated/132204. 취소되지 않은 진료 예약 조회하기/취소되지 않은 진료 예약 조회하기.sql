-- 코드를 입력하세요
SELECT apnt_no, pt_name, p.pt_no, a.mcdp_cd, dr_name, apnt_ymd
from patient p, doctor d, appointment a
where a.pt_no = p.pt_no and a.mddr_id = d.dr_id
and apnt_cncl_yn = 'n'
and a.mcdp_cd = 'cs'
and apnt_ymd like '2022-04-13%'
order by apnt_ymd;