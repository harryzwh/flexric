import sys
import time
import xapp_sdk.xapp_sdk as ric

kpm_hndlr=[]

class KPMCallback(ric.kpm_cb):
    def __init__(self):
        ric.kpm_cb.__init__(self)

    def handle(self, ind):
        print(self.__dict__)
        if ind.msg.type == ric.FORMAT_1_INDICATION_MESSAGE:
            ind_msg = ind.msg.frm_1
        else:
            print(f"unknow message type:{ind.msg.type}")
            return

        for index, meas_data in enumerate(ind_msg.meas_data_lst):
            print(f"meas data idx {index}")
            if meas_data.incomplete_flag == ric.TRUE_ENUM_VALUE:
                print(f"<<< Measurement Record not reliable >>> ")
            for meas_record in meas_data.meas_record_lst:
                if meas_record.value == ric.INTEGER_MEAS_VALUE:
                    print_value = meas_record.int_val
                elif meas_record.value == ric.REAL_MEAS_VALUE:
                    print_value = meas_record.real_val
                elif meas_record.value == ric.NO_VALUE_MEAS_VALUE:
                    print_value = meas_record.no_value
                else:
                    print_value = 0
                    print(f"unknown meas_record")
                print(print_value)

def get_oran_tti(tti):
    if tti == 1:
        return ric.Interval_ms_1
    elif tti == 2:
        return ric.Interval_ms_2
    elif tti == 5:
        return ric.Interval_ms_5
    elif tti == 10:
        return ric.Interval_ms_10
    elif tti == 100:
        return ric.Interval_ms_100
    elif tti == 1000:
        return ric.Interval_ms_1000
    else:
        print(f"Unknown tti {tti}")
        exit()

def main():
    ric.init(sys.argv)
    e2_conns = ric.conn_e2_nodes()
    assert(len(e2_conns) > 0)
    for idx, conn in enumerate(e2_conns):
        print(f"Global E2 Node [{idx}]: PLMN {conn.id.plmn.mcc}.{conn.id.plmn.mnc}")
        if conn.id.type != ric.e2ap_ngran_gNB:
            continue
        for sm_info in ric.get_oran_sm_conf():
            if sm_info.name == "KPM" and sm_info.ran_type== ric.get_e2ap_ngran_name(conn.id.type):
                kpm_cb = KPMCallback()
                hndlr = ric.report_kpm_sm(
                    id=conn.id, 
                    inter = get_oran_tti(sm_info.time), 
                    action = [a for a in sm_info.actions], 
                    handler = kpm_cb
                    )
                kpm_hndlr.append(hndlr)
                time.sleep(1)
    
    while True:
        time.sleep(1)

if __name__=='__main__':
    main()
