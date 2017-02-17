void showPID()
{
	int policy;
	struct sched_param param;
	cout << "\t->PID " <<getpid()<<"\t->TID "<<pthread_self()  << ": ";
	if ((pthread_getschedparam(pthread_self(), &policy, &param)) == 0)
	{
		cout << "Zuteilung: ";
		switch (policy) {
		case SCHED_OTHER:
			cout << "SCHED_OTHER; "; break;
		case SCHED_FIFO:
			cout << "SCHED_FIFO; "; break;
		case SCHED_RR:
			cout << "SCHED_RR; "; break;
		default:
			cout << "Unbekannt; "; break;
		}
	}
	cout << "Priorität: " << param.sched_priority << endl;
}

