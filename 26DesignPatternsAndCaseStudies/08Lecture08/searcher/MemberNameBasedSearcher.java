public class MemberNameBasedSearcher implements MemberSearcher {

    private final string memberName;

    MemberNameBasedSearcher(string memberName) {
        this.memberName = memberName;
    }

    @Override
    public List<Member> Search() {
        return null;
    }
}
