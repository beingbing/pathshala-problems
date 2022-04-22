public class MemberIdBasedSearcher implements MemberSearcher {

    private final int id;

    public MemberIdBasedSearcher(int id) {
        this.id = id;
    }

    @Override
    public List<Member> search() {
        return null;
    }
}
