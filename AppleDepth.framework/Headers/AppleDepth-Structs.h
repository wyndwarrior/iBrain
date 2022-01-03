typedef struct _NSZone {
} // Error Processing Struct Fields

typedef struct CGSize {
    CGFloat width;
    CGFloat height;
} CGSize;

typedef struct __compressed_pair<unsigned long, std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>> {
    NSUInteger __value_;
} __compressed_pair<unsigned long, std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>;

typedef struct __bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>> {
    __compressed_pair<unsigned long, std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>> __data_;
} __bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>;

typedef struct __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> **, std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>> {
    void __value_;
    __bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>> __value_;
} __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> **, std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>>;

typedef struct unique_ptr<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *[], std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>> {
    __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> **, std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>> __ptr_;
} unique_ptr<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *[], std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>>;

typedef struct __hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> {
    void __next_;
} __hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *>;

typedef struct __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *>, std::allocator<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *>>> {
    __hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> __value_;
} __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *>, std::allocator<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *>>>;

typedef struct __compressed_pair<unsigned long, std::__unordered_map_hasher<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::hash<ADLayout>, std::equal_to<ADLayout>, true>> {
    NSUInteger __value_;
} __compressed_pair<unsigned long, std::__unordered_map_hasher<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::hash<ADLayout>, std::equal_to<ADLayout>, true>>;

typedef struct __compressed_pair<float, std::__unordered_map_equal<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::equal_to<ADLayout>, std::hash<ADLayout>, true>> {
    float __value_;
} __compressed_pair<float, std::__unordered_map_equal<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::equal_to<ADLayout>, std::hash<ADLayout>, true>>;

typedef struct __hash_table<std::__hash_value_type<ADLayout, CGSize>, std::__unordered_map_hasher<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::hash<ADLayout>, std::equal_to<ADLayout>, true>, std::__unordered_map_equal<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::equal_to<ADLayout>, std::hash<ADLayout>, true>, std::allocator<std::__hash_value_type<ADLayout, CGSize>>> {
    unique_ptr<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *[], std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *> *>>> __bucket_list_;
    __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *> *>, std::allocator<std::__hash_node<std::__hash_value_type<ADLayout, CGSize>, void *>>> __p1_;
    __compressed_pair<unsigned long, std::__unordered_map_hasher<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::hash<ADLayout>, std::equal_to<ADLayout>, true>> __p2_;
    __compressed_pair<float, std::__unordered_map_equal<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::equal_to<ADLayout>, std::hash<ADLayout>, true>> __p3_;
} __hash_table<std::__hash_value_type<ADLayout, CGSize>, std::__unordered_map_hasher<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::hash<ADLayout>, std::equal_to<ADLayout>, true>, std::__unordered_map_equal<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::equal_to<ADLayout>, std::hash<ADLayout>, true>, std::allocator<std::__hash_value_type<ADLayout, CGSize>>>;

typedef struct unordered_map<ADLayout, CGSize, std::hash<ADLayout>, std::equal_to<ADLayout>, std::allocator<std::pair<const ADLayout, CGSize>>> {
    __hash_table<std::__hash_value_type<ADLayout, CGSize>, std::__unordered_map_hasher<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::hash<ADLayout>, std::equal_to<ADLayout>, true>, std::__unordered_map_equal<ADLayout, std::__hash_value_type<ADLayout, CGSize>, std::equal_to<ADLayout>, std::hash<ADLayout>, true>, std::allocator<std::__hash_value_type<ADLayout, CGSize>>> __table_;
} unordered_map<ADLayout, CGSize, std::hash<ADLayout>, std::equal_to<ADLayout>, std::allocator<std::pair<const ADLayout, CGSize>>>;

typedef struct __CVBuffer {
} // Error Processing Struct Fields

typedef struct CGPoint {
    CGFloat x;
    CGFloat y;
} CGPoint;

typedef struct CGRect {
    CGPoint origin;
    CGSize size;
} CGRect;

typedef struct ? {
    NSUInteger scales;
    id nwarpings;
    BOOL NSMutableArray;
    int useNonLocalRegularization;
    int nlreg_radius;
    float nlreg_padding;
    float nlreg_sigma_l;
    float nlreg_sigma_c;
} ?;

typedef struct CalModel {
    CGFloat field0;
    CGFloat field1;
    CGFloat field2;
    CGFloat field3;
} CalModel;

typedef struct DistortionModel {
    CGFloat field0;
    CGFloat field1;
    CGFloat field2;
    CGFloat field3;
    CGFloat field4;
    CGFloat field5;
} DistortionModel;

typedef struct AdaptiveCorrectionConfig {
    CGFloat epErrorLimitWidePix_FirstPass;
    CGFloat epErrorLimitWidePix_SecondPass;
    CGFloat rangePFL_T;
    CGFloat rangePFL_W;
    CGFloat rangeOCxT;
    CGFloat rangeOCxW;
    CGFloat rangeOCyW;
    CGFloat intermediateMacroDistMM;
    CGFloat extremeMacroDistMM;
    int minPointsForAdjustment;
    CGFloat errorVal_GreaterThanInf;
    CGFloat errorVal_LessThanExtremeMacro;
    CGFloat errorVal_BetweenIntermediate_ExtremeMacro;
    BOOL runAnalyticalPreconditioning;
    CGFloat spgEpsilon;
    float temporalFilteringStrength;
} AdaptiveCorrectionConfig;

typedef struct AdaptiveCorrectionStatus {
    int field0;
    BOOL field1;
    CalModel field2;
    int field3;
    BOOL field4;
    BOOL field5;
    CalModel field6;
    CGFloat field7;
    int field8;
    BOOL field9;
    CGFloat field10;
    CalModel field11;
    BOOL field12;
    int field13;
    BOOL field14;
    CalModel field15;
    CGFloat field16;
    int field17;
    BOOL field18;
    CGFloat field19;
    CalModel field20;
    BOOL field21;
    DistortionModel field22;
    DistortionModel field23;
    int field24;
    BOOL field25;
    CGFloat field26;
    int field27;
    BOOL field28;
    CGFloat field29;
    CalModel field30;
    DistortionModel field31;
    DistortionModel field32;
    BOOL field33;
} AdaptiveCorrectionStatus;

typedef struct AdaptiveCorrection {
} // Error Processing Struct Fields

typedef struct __IOSurface {
} // Error Processing Struct Fields

typedef struct __compressed_pair<unsigned long, std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>> {
    NSUInteger __value_;
} __compressed_pair<unsigned long, std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>;

typedef struct __bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>> {
    __compressed_pair<unsigned long, std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>> __data_;
} __bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>;

typedef struct __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> **, std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>> {
    void __value_;
    __bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>> __value_;
} __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> **, std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>>;

typedef struct unique_ptr<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *[], std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>> {
    __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> **, std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>> __ptr_;
} unique_ptr<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *[], std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>>;

typedef struct __hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> {
    void __next_;
} __hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *>;

typedef struct __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *>, std::allocator<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *>>> {
    __hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> __value_;
} __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *>, std::allocator<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *>>>;

typedef struct __compressed_pair<unsigned long, std::__unordered_map_hasher<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::hash<std::string>, std::equal_to<std::string>, true>> {
    NSUInteger __value_;
} __compressed_pair<unsigned long, std::__unordered_map_hasher<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::hash<std::string>, std::equal_to<std::string>, true>>;

typedef struct __compressed_pair<float, std::__unordered_map_equal<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::equal_to<std::string>, std::hash<std::string>, true>> {
    float __value_;
} __compressed_pair<float, std::__unordered_map_equal<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::equal_to<std::string>, std::hash<std::string>, true>>;

typedef struct __hash_table<std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::__unordered_map_hasher<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::hash<std::string>, std::equal_to<std::string>, true>, std::__unordered_map_equal<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::equal_to<std::string>, std::hash<std::string>, true>, std::allocator<std::__hash_value_type<std::string, PixelBufferSharedPtr>>> {
    unique_ptr<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *[], std::__bucket_list_deallocator<std::allocator<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *> *>>> __bucket_list_;
    __compressed_pair<std::__hash_node_base<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *> *>, std::allocator<std::__hash_node<std::__hash_value_type<std::string, PixelBufferSharedPtr>, void *>>> __p1_;
    __compressed_pair<unsigned long, std::__unordered_map_hasher<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::hash<std::string>, std::equal_to<std::string>, true>> __p2_;
    __compressed_pair<float, std::__unordered_map_equal<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::equal_to<std::string>, std::hash<std::string>, true>> __p3_;
} __hash_table<std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::__unordered_map_hasher<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::hash<std::string>, std::equal_to<std::string>, true>, std::__unordered_map_equal<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::equal_to<std::string>, std::hash<std::string>, true>, std::allocator<std::__hash_value_type<std::string, PixelBufferSharedPtr>>>;

typedef struct unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>> {
    __hash_table<std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::__unordered_map_hasher<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::hash<std::string>, std::equal_to<std::string>, true>, std::__unordered_map_equal<std::string, std::__hash_value_type<std::string, PixelBufferSharedPtr>, std::equal_to<std::string>, std::hash<std::string>, true>, std::allocator<std::__hash_value_type<std::string, PixelBufferSharedPtr>>> __table_;
} unordered_map<std::string, PixelBufferSharedPtr, std::hash<std::string>, std::equal_to<std::string>, std::allocator<std::pair<const std::string, PixelBufferSharedPtr>>>;

typedef struct CGImage {
} // Error Processing Struct Fields

typedef struct __compressed_pair<unsigned char *, std::default_delete<unsigned char []>> {
    char * __value_;
} __compressed_pair<unsigned char *, std::default_delete<unsigned char []>>;

typedef struct unique_ptr<unsigned char [], std::default_delete<unsigned char []>> {
    __compressed_pair<unsigned char *, std::default_delete<unsigned char []>> __ptr_;
} unique_ptr<unsigned char [], std::default_delete<unsigned char []>>;

typedef struct JasperPointCloudDataHeader {
} // Error Processing Struct Fields

typedef struct JasperPointCloud {
    unique_ptr<unsigned char [], std::default_delete<unsigned char []>> m_ownedStorage;
    JasperPointCloudDataHeader m_header;
    NSUInteger m_capacity;
} JasperPointCloud;

typedef struct _NSRange {
    NSUInteger field0;
    NSUInteger field1;
} _NSRange;

typedef struct VZLogger {
} // Error Processing Struct Fields

typedef struct VZDestination {
} // Error Processing Struct Fields

typedef struct ADDistortionPolynomials {
    float forwardOrders;
    float inverseOrders;
} ADDistortionPolynomials;

typedef struct ADWarperMesh {
    NSUInteger _type;
    CGSize _refDimensions;
    id _warperMesh;
    float NSData;
    int _typeOffset;
    int _offsetX;
    int _offsetY;
    int _cropOrigin;
} ADWarperMesh;

typedef struct __compressed_pair<float * __attribute__((ext_vector_type(3))), std::allocator<float __attribute__((ext_vector_type(3)))>> {
} // Error Processing Struct Fields

typedef struct vector<float __attribute__((ext_vector_type(3))), std::allocator<float __attribute__((ext_vector_type(3)))>> {
    __compressed_pair<float * __attribute__((ext_vector_type(3))), std::allocator<float __attribute__((ext_vector_type(3)))>> __begin_;
} vector<float __attribute__((ext_vector_type(3))), std::allocator<float __attribute__((ext_vector_type(3)))>>;

